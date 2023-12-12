//
// Created by lhu on 12.12.23.
//


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
