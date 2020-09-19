#include <assert.h>
#include <csvreader.h>
#include <iostream>
#include <string>
#include <vector>

void print_test_function(std::string function_name)
{
	std::cout << "Running " << function_name << std::endl;
}

template<typename T>
void assert_equals(T expected, T actual)
{
	if (expected != actual)
	{
		std::cout << "Value different. caller=" << __builtin_FUNCTION() << ", expected=" << expected << ", actual=" << actual << std::endl;
	}
	assert(expected == actual);
}

void test_csv_reader_read_csv()
{
	print_test_function(__func__);
	std::vector<std::vector<std::string>> expected_table = {
		{"One", "Two", "Three"},
		{"1", "2", "3"},
		{"4", "5", "6"}
	                                                     };
	std::vector<std::vector<std::string>> actual_table = AA::csvreader::read_csv("resources/test/csvreader_test.csv");

	assert_equals(expected_table.size(), actual_table.size());
	for (int i = 0; i < expected_table.size(); ++i)
	{
		assert_equals(expected_table[i].size(), actual_table[i].size());
		for (int j = 0; j < expected_table[i].size(); ++j)
		{
			assert_equals(expected_table[i][j], actual_table[i][j]);
		}
	}
}

int main()
{
	std::cout << "Start running test..." << std::endl;
	test_csv_reader_read_csv();
	std::cout << "Test success." << std::endl;
}
