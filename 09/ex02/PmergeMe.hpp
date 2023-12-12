//
// Created by lhu on 12.12.23.
//

#ifndef EX02_PMERGEME_HPP
# define EX02_PMERGEME_HPP

# include <iostream>
# include <vector>

class PmergeMe {
public:
	static void insertionSort(std::vector<int> & A, int p, int q);
	static void merge(std::vector<int> & A, int p, int q, int r);
	static void sort(std::vector<int> & A, int p, int r);

private:
	static const int K = 5;
	static std::vector<int> copy_range(std::vector<int> A, int from, int to);
};


#endif //EX02_PMERGEME_HPP
