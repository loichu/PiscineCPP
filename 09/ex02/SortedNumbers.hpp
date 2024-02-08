//
// Created by lhu on 23.01.24.
//

#ifndef EX02_SORTEDNUMBERS_HPP
#define EX02_SORTEDNUMBERS_HPP

#include <cstdlib>
#include <vector>
#include <iostream>
#include <algorithm>

class SortedNumbers {
private:
	static SortedNumbers* only_instance;
	std::size_t max_index;
	std::vector<int> numbers;
	SortedNumbers();
public:
	static SortedNumbers& instance();
	static void addNumber(int i);
	static std::vector<int> getNumbers();
	static void resetMaxIndex();
	static void destroyInstance();
};


#endif //EX02_SORTEDNUMBERS_HPP
