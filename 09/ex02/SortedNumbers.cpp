//
// Created by lhu on 23.01.24.
//

#include "SortedNumbers.hpp"

SortedNumbers* SortedNumbers::only_instance = &instance();

SortedNumbers::SortedNumbers()
{
	max_index = 0;
}

SortedNumbers& SortedNumbers::instance()
{
	if (only_instance == NULL)
		only_instance = new SortedNumbers();
	return *only_instance;
}

void SortedNumbers::addNumber(int i)
{
	size_t size = only_instance->numbers.size();

//	std::cout << "\nSize: " << size << std::endl;

	if (size < 2)
		return only_instance->numbers.push_back(i);

//	std::vector<int>::iterator numbers_it = only_instance->numbers.begin();
//
//
//	size_t upper_bound = only_instance->max_index;
//	size_t lower_bound = 0;
//	size_t current_index;

	std::cout << "\nWill insert " << i << std::endl;

	std::vector<int>::iterator numbers_it = std::upper_bound(
			only_instance->numbers.begin(),
			only_instance->numbers.begin() + only_instance->max_index,
			i
			);

	only_instance->numbers.insert(numbers_it, i);

//	std::cout << "Inserted " << i << " at " << current_index << "\n" << std::endl;

	only_instance->max_index += 2;

//	while (upper_bound - lower_bound > 1)
//	{
//		current_index = (upper_bound + lower_bound) / 2;
//		numbers_it = only_instance->numbers.begin();
//		std::advance(numbers_it, current_index);
//
//		std::cout << lower_bound << " - " << upper_bound << std::endl;
//		std::cout << "Current index: " << current_index << std::endl;
//
//
//		if (i == *numbers_it)
//			break;
//
//		if (i < *numbers_it)
//			upper_bound = current_index - 1;
//		else
//			lower_bound = current_index + 1;
//	}
//
//	only_instance->numbers.insert(numbers_it, i);
//
//	std::cout << "Inserted " << i << " at " << current_index << "\n" << std::endl;
//
//	only_instance->max_index += 2;
}

std::vector<int> SortedNumbers::getNumbers() {
	return only_instance->numbers;
}

void SortedNumbers::resetMaxIndex() {
	instance().max_index = 0;
}
