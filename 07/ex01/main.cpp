//
// Created by lhu on 15.11.23.
//

#include "iter.hpp"

void add_one(int & n)
{
	n++;
}

int main( void ) {
	int a[] = {4, 5, 200};
	iter(a, 3, &print);
	iter(a, 3, &add_one);
	iter(a, 3, &print);

	std::string b[] = {"hello", "salut"};
	iter(b, 2, &print);
}
