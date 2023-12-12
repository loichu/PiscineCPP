#include "PmergeMe.hpp"

//int main(int argc, char **argv)
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

	PmergeMe::sort(A, 0, len - 1);

	for (int i = 0; i < len; ++i)
		std::cout << A[i] << " " << std::flush;
	std::cout << std::endl;

	return 0;
}
