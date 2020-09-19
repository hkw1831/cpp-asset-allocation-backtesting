#pragma once

#include <iostream>
#include <vector>

namespace AA
{
	template<typename T>
	void displayTable(std::vector<std::vector<T>> table)
	{
		for (std::vector<T> row : table)
		{
			for (T entry : row)
			{
				std::cout << entry << ' ';
			}
			std::cout << std::endl;
		}
	}
}
