//
// Created by lhu on 12.12.23.
//

#ifndef EX02_PMERGEME_HPP
# define EX02_PMERGEME_HPP

# include <iostream>
# include <vector>
# include "GroupIterator.hpp"

class PmergeMe {
public:
	static void insertionSort(std::vector<int> & A, int p, int q);
	static void merge(std::vector<int> & A, int p, int q, int r);
	static void sort(std::vector<int> & A, int p, int r);
//	static std::vector< std::vector<int> > sort(std::vector<int> & numbers);
	static std::vector<int> sort(std::vector<int> & numbers);

private:
	static const int K = 5;
	static std::vector<int> copy_range(std::vector<int> A, int from, int to);

	static std::vector< std::vector<int> > make_pairs(const std::vector<int> & numbers);
	static void sort_each_pair(std::vector< std::vector<int> > & pairs);
//	static void sort_all_pairs(std::vector< std::vector<int> > & pairs);

//	static std::vector<int> make_group(const std::vector< std::vector<int> > & pairs, int index);

};

template<typename Iterator>
void sort_recursive(Iterator start, Iterator end)
{
	Iterator it = start;
	while (it < end)
		std::cout << *it++ << " " << std::flush;
	std::cout << std::endl;
	std::size_t distance = std::distance(start, end);
	std::cout << "distance: " << distance << std::endl;
	if (distance < 2)
		return;
	test_recursive(make_group_iterator(start, 2),
	               make_group_iterator(end, 2));
}



#endif //EX02_PMERGEME_HPP
