#include <algorithm>
#include <ctime>
#include <list>
#include "PmergeMe.hpp"
#include "GroupIterator.hpp"

//int main(int argc, char **argv)

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

void test_sort(int number)
{
	std::vector<int> numbers = random_vector(number);
	std::vector<int> vec = PmergeMe::sort(numbers);
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
}

int main()
{
	int len = 9;

	int test[] = { 2, 5, 1, 6, 7, 3, 8, 4, 9 };

	std::vector<int> A(len);

	for (int i = 0; i < len; ++i)
		A[i] = test[i];

	for (int i = 0; i < len; ++i)
		std::cout << A[i] << " " << std::flush;
	std::cout << std::endl;

	std::vector<int> sorted = PmergeMe::sort(A);

	std::cout << std::endl << "sorted:" << std::endl;
	for (int i = 0; i < len; ++i)
		std::cout << sorted[i] << " " << std::flush;
	std::cout << std::endl;

	std::srand(std::time(NULL));
	test_sort(10);
//	test_sort(100);

	test_group_iterator();

	std::cout << "\n\nSTARTING FOR REAL\n" << std::endl;

	static const int numbers[] = {5,1,8,2,3,6,9,4};
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

	return 0;
}
