#pragma once

#include <fstream>
#include <iostream>
#include <istream>
#include <string>
#include <vector>

namespace AA
{
	class csvreader
	{
	public:
		static std::vector<std::vector<std::string>> read_csv(std::istream &in);
		static std::vector<std::vector<std::string>> read_csv(std::string path);
	private:
		static std::vector<std::string> read_csv_row(const std::string &row);
	};
}
