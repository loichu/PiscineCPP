//
// Created by lhu on 12.12.23.
//

#ifndef EX02_PMERGEME_HPP
# define EX02_PMERGEME_HPP

# include <iostream>
# include <vector>
#include <list>
#include <algorithm>
#include <utility>
#include <iterator>
# include "GroupIterator.hpp"
# include "SortedNumbers.hpp"

class PmergeMe {
public:
	static void insertionSort(std::vector<int> & A, int p, int q);
	static void merge(std::vector<int> & A, int p, int q, int r);
	static void sort(std::vector<int> & A, int p, int r);
	static std::vector<int> sort(std::vector<int> & numbers);

private:
	static const int K = 5;
	static std::vector<int> copy_range(std::vector<int> A, int from, int to);

	static std::vector< std::vector<int> > make_pairs(const std::vector<int> & numbers);
	static void sort_each_pair(std::vector< std::vector<int> > & pairs);
};

template<typename Iterator>
void iter_swap(GroupIterator<Iterator> lhs, GroupIterator<Iterator> rhs)
{
	std::swap_ranges(lhs.base(), lhs.base() + lhs.size(), rhs.base());
}

template<typename Iterator>
Iterator next(Iterator it)
{
	std::advance(it, 1);
	return it;
}

template<typename Iterator>
void sort_recursive(Iterator start, Iterator end) {
	for (Iterator it = start; it < end; ++it)
		std::cout << *it << " " << std::flush;
	std::cout << std::endl;

	std::size_t distance = std::distance(start, end);
	if (distance < 2)
		return;

	for (Iterator it = start; it != end; it += 2) {
//		std::cout << "Compare " << it[0] << " and " << it[1] << std::endl;
		if (it[1] < it[0]) {
			std::cout << "Swapped " << it[0] << " and " << it[1] << std::endl;
			iter_swap(it, it + 1);
			for (Iterator itt = start; itt < end; ++itt)
				std::cout << *itt << " " << std::flush;
			std::cout << std::endl;
		}
	}

	sort_recursive(make_group_iterator(start, 2),
	               make_group_iterator(end, 2));

	std::vector<Iterator> chain;
	chain.push_back(start);
	chain.push_back(next(start));
//	chain.insert(chain.begin(), *start);
//	chain.insert(chain.begin(), *next(start));

	std::cout << "\nNumbers in current range: ";
	for (Iterator it = start; it != end; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	typename std::vector<Iterator>::iterator chain_it;
	std::cout << "Main chain: ";
	for (chain_it = chain.begin(); chain_it != chain.end(); ++chain_it) {
		std::cout << **chain_it << " ";
	}
	std::cout << std::endl;

	std::vector<typename std::vector<Iterator>::iterator> pend;
	for (Iterator it = start + 2; it != end; it += 2) {
//		std::vector<Iterator> tmp = chain.insert(chain.end(), next(it));
		std::cout << "Next: " << *next(it) << std::endl;
		typename std::vector<Iterator>::iterator tmp =
				chain.insert(chain.end(), next(it));
		std::cout << "Next pend: " << **tmp << std::endl;
		pend.push_back(tmp);
	}

//	std::vector<typename std::vector<Iterator>::iterator> pend;
//	for (Iterator it = start + 2; it != end; it += 2) {
////		std::vector<Iterator> tmp = chain.insert(chain.end(), next(it));
//		std::cout << "Next: " << *next(it) << std::endl;
//		typename std::vector<Iterator>::iterator tmp =
//				chain.insert(chain.end(), next(it));
//		std::cout << "Next pend: " << **tmp << std::endl;
//		pend.push_back(tmp);
//	}
//
//	typename std::vector<Iterator>::iterator chain_it;
//	std::cout << "Main: ";
//	for (chain_it = chain.begin(); chain_it != chain.end(); ++chain_it) {
//		std::cout << **chain_it << " ";
//	}
//	std::cout << std::endl;
//
//	typename std::vector<typename std::vector<Iterator>::iterator>::iterator pend_it;
//	std::cout << "Pend: ";
//	for (pend_it = pend.begin(); pend_it != pend.end(); ++pend_it) {
//		std::cout << ***pend_it << " ";
//	}
//	std::cout << std::endl;


//	std::cout << "\nNumbers in current range: ";
//	for (Iterator it = start; it != end; ++it)
//		std::cout << *it << " ";
//	std::cout << std::endl;

//	SortedNumbers::resetMaxIndex();
//
//	std::cout << "Numbers to insert: ";
//	for (Iterator it = start; it != end; it += 2) {
//		std::cout << *it << " ";
//	}
//	std::cout << std::endl;
//
//	if (std::distance(start, end) <= 2)
//	{
//		for (Iterator it = start; it != end; ++it) {
////			std::cout << *it << " ";
//			SortedNumbers::addNumber(*it);
//		}
//	} else {
//		for (Iterator it = start; it < end; it += 2) {
////			std::cout << *it << " ";
//			SortedNumbers::addNumber(*it);
//		}
//	}
//
//	std::cout << "\nInserted numbers:  ";
//	std::vector<int> numbers = SortedNumbers::getNumbers();
//	std::vector<int>::iterator ins_it;
//	for (ins_it = numbers.begin(); ins_it != numbers.end(); ++ins_it) {
//		std::cout << *ins_it << " ";
//	}
//	std::cout << std::endl;
}



#endif //EX02_PMERGEME_HPP
