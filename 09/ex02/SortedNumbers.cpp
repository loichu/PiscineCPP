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
	size_t size = instance().numbers.size();

	std::cout << "\nCurrent list : ";
	std::vector<int>::iterator num_it;
	for (num_it = instance().numbers.begin(); num_it < instance().numbers.end(); ++num_it)
		std::cout << *num_it << ' ';
	std::cout << std::endl;


	if (size < 2)
		return only_instance->numbers.push_back(i);

	std::cout << "Will insert " << i << std::endl;
	std::cout << "Max index " << only_instance->max_index << std::endl;

	std::vector<int>::iterator numbers_it = std::upper_bound(
			only_instance->numbers.begin(),
			only_instance->numbers.begin() + only_instance->max_index,
			i
			);

	std::cout << "Inserted at: " << numbers_it - only_instance->numbers.begin() << std::endl;

	only_instance->numbers.insert(numbers_it, i);

	only_instance->max_index += 2;
}

std::vector<int> SortedNumbers::getNumbers() {
	return instance().numbers;
}

void SortedNumbers::resetMaxIndex() {
	instance().max_index = 0;
}

void SortedNumbers::destroyInstance() {
	delete only_instance;
	only_instance = NULL;
}
