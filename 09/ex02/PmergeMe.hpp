//
// Created by lhu on 12.12.23.
//

#ifndef EX02_PMERGEME_HPP
# define EX02_PMERGEME_HPP

# include <iostream>
# include <vector>
#include <list>
# include "GroupIterator.hpp"
# include "SortedNumbers.hpp"

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
void iter_swap(GroupIterator<Iterator> lhs, GroupIterator<Iterator> rhs)
{
	std::swap_ranges(lhs.base(), lhs.base() + lhs.size(), rhs.base());
}

//template<typename Iterator>
void insert_without_jacobsthal(std::vector<int> & main_chain, std::vector<int> & pend);

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
//	std::cout << "distance: " << distance << std::endl;
	if (distance < 2)
		return;

//	using std::iter_swap;

	for (Iterator it = start; it != end; it += 2) {
		std::cout << "Compare " << it[0] << " and " << it[1] << std::endl;
		if (it[1] < it[0]) {
			std::cout << "Swapped " << it[0] << " and " << it[1] << std::endl;
			iter_swap(it, it + 1);
		}
	}

	sort_recursive(make_group_iterator(start, 2),
	               make_group_iterator(end, 2));

//	std::cout << "Recursion passed" << std::endl;

//	std::vector<int> main_chain;
//	std::vector<int> pend;
//	std::list<Iterator> main_chain;
//	main_chain.insert(main_chain.begin(), start);
//	main_chain.insert(main_chain.begin(), next(start));
//	std::vector<typename std::list<Iterator>::iterator> pend;
//
//	for (Iterator it = start + 2; it != end; it += 2) {
////		pend.push_back(it[0]);
////		main_chain.push_back(it[1]);
//		Iterator next_it = next(it);
//		typename std::list<Iterator>::iterator tmp = main_chain.insert(
//				main_chain.end(), next_it);
//		std::cout << "Chain: ";
//		typename std::list<Iterator>::iterator chain_it;
//		for (chain_it = main_chain.begin(); chain_it != main_chain.end(); ++chain_it)
//			std::cout << **chain_it << " " << std::flush;
//		std::cout << std::endl;
//
////		Iterator tmp_it = *tmp;
////		std::cout << "Add " << tmp_it.base() << " to pend\n" << std::endl;
//		pend.push_back(tmp);
//	}

//	std::vector<int> inserted;

	std::cout << "\nNumbers in current range: ";
	for (Iterator it = start; it != end; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	SortedNumbers::resetMaxIndex();

	std::cout << "\nNumbers to insert: ";
	if (std::distance(start, end) <= 2)
	{
		for (Iterator it = start; it != end; ++it) {
			std::cout << *it << " ";
//		inserted.push_back(*it);
			SortedNumbers::addNumber(*it);
		}
	} else {
		for (Iterator it = start; it < end; it += 2) {
			std::cout << *it << " ";
//		inserted.push_back(*it);
			SortedNumbers::addNumber(*it);
		}
	}

	std::cout << "\nInserted numbers:  ";
	std::vector<int> numbers = SortedNumbers::getNumbers();
	std::vector<int>::iterator ins_it;
//	size_t size = inserted.size();
//	for (size_t i = 0; i < size; ++i) {
	for (ins_it = numbers.begin(); ins_it != numbers.end(); ++ins_it) {
		std::cout << *ins_it << " ";
	}
	std::cout << std::endl;

//	std::cout << "Pend and main chain created" << std::endl;

//	std::vector<int>::iterator it;

//	typename std::list<Iterator>::iterator chain_it;
//	typename std::vector<
//	        typename std::list<Iterator>::iterator>::iterator pend_it;
//
//	std::cout << "Pend: ";
//	for (pend_it = pend.begin(); pend_it != pend.end(); ++pend_it) {
//		typename std::list<Iterator>::iterator pend_iterator;
//		std::cout << **pend_iterator << " " << std::flush;
//	}
//	std::cout << std::endl;
//
//	std::cout << "Chain: ";
//	for (chain_it = main_chain.begin(); chain_it != main_chain.end(); ++chain_it)
//		std::cout << **chain_it << " " << std::flush;
//	std::cout << "\n" << std::endl;
//
//	std::cout << "End function\n" << std::endl;

//	insert_without_jacobsthal(main_chain, pend);
}



#endif //EX02_PMERGEME_HPP
