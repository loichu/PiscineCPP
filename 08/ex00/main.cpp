//
// Created by lhu on 23.11.23.
//

#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>

int main()
{
	int arr[] = {3, 53, 56, 100, -2};
	int size = sizeof(arr) / sizeof(arr[0]);
	std::vector<int> vect(arr, arr + size);
	std::deque<int> deq(arr, arr + size);
	std::list<int> lst(arr, arr + size);

	easyfind(vect, 3);
	easyfind(vect, 4);

	easyfind(deq, 53);
	easyfind(deq, 54);

	easyfind(lst, -2);
	easyfind(lst, -3);

	return 0;
}
