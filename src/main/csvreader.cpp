#include <csvreader.h>

enum class CSVState
{
	UnquotedField,
	QuotedField,
	QuotedQuote
};

inline std::string trim_string(std::string& str)
{
    str.erase(0, str.find_first_not_of(' '));       //prefixing spaces
    str.erase(str.find_last_not_of(' ')+1);         //surfixing spaces
    return str;
}

std::vector<std::string> AA::csvreader::read_csv_row(const std::string &row)
{
	CSVState state = CSVState::UnquotedField;
	std::vector<std::string> fields {""};
	size_t i = 0; // index of the current field
	for (char c : row)
	{
		switch (state)
		{
			case CSVState::UnquotedField:
				switch (c)
				{
					case ',': // end of field
						fields.push_back("");
						++i;
						break;
					case '"':
						state = CSVState::QuotedField;
						break;
					default:
						fields[i].push_back(c);
						break;
				}
				break;
			case CSVState::QuotedField:
				switch (c)
				{
					case '"': 
						state = CSVState::QuotedQuote;
						break;
					default:
						fields[i].push_back(c);
						break;
				}
				break;
			case CSVState::QuotedQuote:
				switch (c)
				{
					case ',': // , after closing quote
						fields.push_back("");
						++i;
						state = CSVState::UnquotedField;
						break;
					case '"': // "" -> "
						fields[i].push_back('"');
						state = CSVState::QuotedField;
						break;
					default: // end of quote
						state = CSVState::UnquotedField;
						break;
				}
				break;
		}
	}

	// trim space for the content
	for (int i = 0; i < fields.size(); ++i)
	{
		fields[i] = trim_string(fields[i]);
	}
	return fields;
}

std::vector<std::vector<std::string>> AA::csvreader::read_csv(std::istream &in)
{
	std::vector<std::vector<std::string>> table;
	std::string row;
	while (!in.eof())
	{
		std::getline(in, row);
		if (in.bad() || in.fail())
		{
			break;
		}
		auto fields = read_csv_row(row);
		table.push_back(fields);
	}
	return table;
}

std::vector<std::vector<std::string>> AA::csvreader::read_csv(std::string path)
{
	std::ifstream file(path);
	return read_csv(file);
}

