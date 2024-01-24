//
// Created by lhu on 12.12.23.
//


#include <cstdlib>
#include "PmergeMe.hpp"

void PmergeMe::insertionSort(std::vector<int> & A, int p, int q) {
	for (int i = p; i < q; i++) {
		int tempVal = A[i + 1];
		int j = i + 1;
		while (j > p && A[j - 1] > tempVal) {
			A[j] = A[j - 1];
			j--;
		}
		A[j] = tempVal;
	}
	std::vector<int> temp = copy_range(A, p, q +1);

	for (std::size_t i = 0; i < temp.size(); ++i)
		std::cout << temp[i] << " " << std::flush;
	std::cout << std::endl;
}

void PmergeMe::merge(std::vector<int> & A, int p, int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;
	std::vector<int> LA = copy_range(A, p, q +1);
	std::vector<int> RA = copy_range(A, q+1, r +1);
	int RIDX = 0;
	int LIDX = 0;
	for (int i = p; i < r - p + 1; i++) {
		if (RIDX == n2) {
			A[i] = LA[LIDX];
			LIDX++;
		} else if (LIDX == n1) {
			A[i] = RA[RIDX];
			RIDX++;
		} else if (RA[RIDX] > LA[LIDX]) {
			A[i] = LA[LIDX];
			LIDX++;
		} else {
			A[i] = RA[RIDX];
			RIDX++;
		}
	}
}

void PmergeMe::sort(std::vector<int> & A, int p, int r) {
	if (r - p > K) {
		int q = (p + r) / 2;
		sort(A, p, q);
		sort(A, q + 1, r);
		merge(A, p, q, r);
	} else {
		insertionSort(A, p, r);
	}
}

std::vector<int> PmergeMe::copy_range(std::vector<int> A, int from, int to) {
	std::vector<int> res;

	for (int i = from; i < to; ++i)
		res.push_back(A[i]);

	return res;
}

std::vector<int> PmergeMe::sort(std::vector<int> & numbers)
{
	if (numbers.empty())
		return numbers;
	std::vector< std::vector<int> > pairs = PmergeMe::make_pairs(numbers);
	PmergeMe::sort_each_pair(pairs);

	{
		std::vector< std::vector<int> >::iterator it_pair;
		std::cout << "Pairs: " << std::endl;
		for (it_pair = pairs.begin(); it_pair < pairs.end(); ++it_pair)
		{
			std::vector<int>::iterator it_num;
			for (it_num = it_pair->begin(); it_num < it_pair->end(); ++it_num)
				std::cout << *it_num << " " << std::flush;
			std::cout << std::endl;
		}
	}


	if (pairs.size() == 1)
		return pairs[0];
//	if (pairs.size() == 2)
//	{
//		if (pairs[0][0] > pairs[1][0])
//		{
//			std::vector<int> res(pairs[1]);
//			res.insert(res.end(), pairs[0].begin(), pairs[0].end());
//			return res;
//		}
//		else
//		{
//			std::vector<int> res(pairs[0]);
//			res.insert(res.end(), pairs[1].begin(), pairs[1].end());
//			return res;
//		}
//	}


	// STEP 3: divide pairs in two groups
	std::vector<int> group_a;
	std::vector<int> group_b;
	std::vector< std::vector<int> >::const_iterator it_pair;
	for (it_pair = pairs.begin(); it_pair < pairs.end(); ++it_pair)
	{
		if (it_pair->size() == 2)
		{
			group_a.push_back((*it_pair)[0]);
			group_b.push_back((*it_pair)[1]);
		}
		else
		{
			group_b.push_back((*it_pair)[0]);
		}
	}

	// STEP 4: sort group A recursively to get the main chain
	std::vector<int> main_chain = sort(group_a);

	std::cout << "Chain:" << std::endl;
	for (size_t i = 0; i < main_chain.size(); ++i)
		std::cout << main_chain[i] << " " << std::flush;
	std::cout << std::endl;

	// STEP 5: insert group B inside A with a binary search insertion.
	// Because A is sorted, and we insert B that is a bigger number than
	// the corresponding index in A, we don't need to search further in
	// the chain. It's quite difficult to track though...
	std::vector<int>::iterator it_b;
	for (it_b = group_b.begin(); it_b < group_b.end(); ++it_b)
	{
		int min_index = 0;
		int max_index = main_chain.size();
		int ins_index = (min_index + max_index) / 2;

		if (*it_b > main_chain[max_index])
		{
			main_chain.push_back(*it_b);
			continue;
		}
		if (*it_b < main_chain[min_index])
		{
			main_chain.insert(main_chain.begin(), *it_b);
			continue;
		}

		while (ins_index != min_index && ins_index != max_index)
		{

			std::cout << "\nMin: " << min_index << " Max: " << max_index << " Ins: " << ins_index <<  std::endl;

			if (*it_b >= main_chain[ins_index])
			{
				std::cout << *it_b << " Gte " << main_chain[ins_index] << std::endl;
				min_index = ins_index;
			}

			if (*it_b <= main_chain[ins_index])
			{
				std::cout << *it_b << " Lte " << main_chain[ins_index] << std::endl;
				max_index = ins_index;
			}

			ins_index = (min_index + max_index) / 2;

			std::cout << "Min: " << min_index << " Max: " << max_index << " Ins: " << ins_index << std::endl ;

		}
		std::cout << "Insert " << *it_b << std::endl;
		main_chain.insert(main_chain.begin() + ins_index, *it_b);
	}

	return main_chain;
}

// STEP 1: divide into pairs
std::vector< std::vector<int> > PmergeMe::make_pairs(const std::vector<int> & numbers)
{
	std::vector< std::vector<int> > pairs;
	std::vector<int>::const_iterator it_num = numbers.begin();

	for (; it_num < numbers.end(); ++it_num)
	{
		std::vector<int>::const_iterator it_even = it_num;
		std::vector<int>::const_iterator it_odd = ++it_num;
		if (it_odd != numbers.end())
			pairs.push_back(std::vector<int>(it_even, it_odd + 1));
		else
			pairs.push_back(std::vector<int>(1, *it_even));
	}

	return pairs;
}

// STEP 2: sort pairs internally
void PmergeMe::sort_each_pair(std::vector< std::vector<int> > & pairs)
{
	std::vector< std::vector<int> >::iterator it_pair;
	for (it_pair = pairs.begin(); it_pair < pairs.end(); ++it_pair)
	{
		if (it_pair->size() == 2 && (*it_pair)[1] < (*it_pair)[0])
		{
			int tmp = (*it_pair)[1];
			(*it_pair)[1] = (*it_pair)[0];
			(*it_pair)[0] = tmp;
		}
	}
}
//
//std::vector<int> PmergeMe::make_group(const std::vector< std::vector<int> > & pairs, int index) {
//	std::vector<int> group;
//	std::vector< std::vector<int> >::const_iterator it_pair;
//	for (it_pair = pairs.begin(); it_pair < pairs.end(); ++it_pair)
//		group.push_back((*it_pair)[index]);
//	return group;
//}

void insert(int i, std::vector<int> & main_chain, size_t max_index)
{
	size_t upper_bound = max_index;
	size_t lower_bound = 0;
	size_t current_index;
//	int prev_index = max_index;
	std::vector<int>::iterator main_chain_it;

	std::cout << "Will insert " << i << std::endl;

	while (upper_bound - lower_bound > 1)
	{
		current_index = (upper_bound + lower_bound) / 2;
		main_chain_it = main_chain.begin();
		std::advance(main_chain_it, current_index);

		std::cout << lower_bound << " - " << upper_bound << std::endl;

		if (i == *main_chain_it)
			break;

		if (i < *main_chain_it)
			upper_bound = current_index;
		else
			lower_bound = current_index;
	}

	main_chain.insert(main_chain_it, i);

}

void insert_without_jacobsthal(std::vector<int> & main_chain, std::vector<int> & pend)
{
	std::vector<int>::iterator main_chain_it = main_chain.begin();
	main_chain.insert(main_chain_it, pend[0]);

	size_t i = 0;
	while (i < pend.size())
	{
		insert(pend[i], main_chain, i * 2);
		i += 1;
	}
}
