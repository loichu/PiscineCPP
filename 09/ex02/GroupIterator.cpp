//
// Created by lhu on 25.12.23.
//

#include "GroupIterator.hpp"
#include <vector>
#include <list>

void test_group_iterator()
{
	static const int numbers[] = {5,1,8,2,3,6,4,9};
	std::vector<int> vec_numbers (numbers, numbers + sizeof(numbers) / sizeof(numbers[0]));
	std::list<int> lst_numbers (numbers, numbers + sizeof(numbers) / sizeof(numbers[0]));

	test_recursive<std::vector<int>::iterator>(vec_numbers.begin(), vec_numbers.end());
}