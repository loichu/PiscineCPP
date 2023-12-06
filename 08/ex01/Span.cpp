//
// Created by lhu on 24.11.23.
//

#include "Span.hpp"

Span::Span() : _n(0) {}

Span::Span(std::size_t n) : _n(n) {}

Span::Span(const Span &span) : _n(span._n) {
	*this = span;
}

Span::~Span() {}

Span &Span::operator=(const Span &span) {
	_n = span._n;
	_numbers = span._numbers;
	return *this;
}

void Span::addNumber(int n) {
	if (_numbers.size() + 1 > _n)
		throw std::out_of_range("Span is already full");
	_numbers.push_back(n);
}

void Span::addNumber(std::vector<int>::iterator start, std::vector<int>::iterator end) {
	if (_numbers.size() + std::distance(start, end) > _n)
		throw std::out_of_range("Range is too big or span is already full");
	_numbers.insert(_numbers.end(), start, end);
}

std::size_t Span::shortestSpan() const {
	if (_numbers.size() < 2)
		throw std::out_of_range("At least 2 numbers in the span are required");

	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());
	size_t shortest = longestSpan();

	for (size_t i = 0; i + 1 < sorted.size(); ++i)
	{
		size_t distance = abs(sorted[i] - sorted[i + 1]);
		if (distance < shortest)
			shortest = distance;
	}

	return shortest;
}

std::size_t Span::longestSpan() const {
	if (_numbers.size() < 2)
		throw std::out_of_range("At least 2 numbers in the span are required");
	int min = *std::min_element(_numbers.begin(), _numbers.end());
	int max = *std::max_element(_numbers.begin(), _numbers.end());
	return abs(max - min);
}
