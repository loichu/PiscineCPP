//
// Created by lhu on 24.11.23.
//

#ifndef EX01_SPAN_HPP
# define EX01_SPAN_HPP
# include <iostream>
# include <stdexcept>
# include <algorithm>
# include <vector>


class Span {
	public:
	Span(std::size_t n);
	Span(const Span & span);
	~Span();
	Span & operator = (const Span & span);

	void addNumber(int n);
	void addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end);

	std::size_t shortestSpan() const;
	std::size_t longestSpan() const;

	private:
	Span();
	std::size_t         _n;
	std::vector<int>    _numbers;
};


#endif //EX01_SPAN_HPP
