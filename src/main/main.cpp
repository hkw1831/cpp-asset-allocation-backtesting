#include <csvreader.h>
#include <displayer.h>
#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::vector<std::vector<std::string>> table = AA::csvreader::read_csv("resources/testread.csv");
	AA::displayTable<std::string>(table);
}
