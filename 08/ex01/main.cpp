//
// Created by lhu on 23.11.23.
//

#include "Span.hpp"
#include <list>
#include <ctime>
#include <valarray>

void fill_random_span(Span & span, size_t size) {
	std::vector<int> vec(size);
	std::generate(vec.begin(), vec.end(), std::rand);
	span.addNumber(vec.begin(), vec.end());
}

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	try {
		sp.addNumber(90);
		std::cout << "FAIL - add another number" << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::srand(std::time(NULL));

	{
		int size = 10000;
		Span sp2 = Span(size);


		try {
			fill_random_span(sp2, size + 1);
			std::cout << "FAIL - add range too big" << std::endl;
		} catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
			fill_random_span(sp2, size / 2);
		}
	}

	{
		int size = 10000;
		Span sp2 = Span(size);
		fill_random_span(sp2, size);
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}

	return 0;
}
