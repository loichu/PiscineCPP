#include <algorithm>
#include <ctime>
#include <list>
#include "PmergeMe.hpp"
#include "GroupIterator.hpp"

std::vector<int> random_vector(size_t size) {
	std::vector<int> vec(size);
	std::generate(vec.begin(), vec.end(), std::rand);
	return vec;
}

bool is_ordered(std::vector<int> vec)
{
	int prev = 0;
	std::vector<int>::iterator it;
	for (it = vec.begin(); it < vec.end(); ++it)
	{
		if (it != vec.begin() && prev > *it)
		{
			std::cout << "Curr " << *it << std::endl;
			std::cout << "Prev " << prev << std::endl;
			return false;
		}
		prev = *it;
	}
	return true;
}

void test_sort_vector(int number)
{
	std::vector<int> numbers = random_vector(number);
	sort_recursive<std::vector<int>::iterator>(numbers.begin(), numbers.end());
//	std::vector<int> vec = PmergeMe::sort(numbers);
	std::vector<int> vec = SortedNumbers::getNumbers();
	if (is_ordered(vec))
	{
		std::cout << "OK" << std::endl;
	}
	else
	{
		std::cout << "KO" << std::endl;
		std::vector<int>::iterator it;
		for (it = vec.begin(); it < vec.end(); ++it) {
			std::cout << *it << std::endl;
		}
	}
	SortedNumbers::destroyInstance();
}

int main()
{
//	static const int numbers[] = {5,1,8,2,3,6,9,4};
	static const int numbers[] = {3,7,1,2,4,5,6,0};
	std::vector<int> vec_numbers (numbers, numbers + sizeof(numbers) / sizeof(numbers[0]));
	std::list<int> lst_numbers (numbers, numbers + sizeof(numbers) / sizeof(numbers[0]));

	std::vector<int>::iterator vec_it;
	for (vec_it = vec_numbers.begin(); vec_it < vec_numbers.end(); ++vec_it)
		std::cout << *vec_it << " " << std::flush;
	std::cout << std::endl;

	sort_recursive<std::vector<int>::iterator>(vec_numbers.begin(), vec_numbers.end());

	for (vec_it = vec_numbers.begin(); vec_it < vec_numbers.end(); ++vec_it)
		std::cout << *vec_it << " " << std::flush;
	std::cout << std::endl;

//	test_sort_vector(8);

	return 0;
}
