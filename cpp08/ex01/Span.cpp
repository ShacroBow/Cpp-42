#include "Span.hpp"
#include <algorithm>

Span::Span() : _max(0) {}

Span::Span(unsigned int n) : _max(n) {}

Span::Span(Span const &other) : _max(other._max), _vec(other._vec) {}

Span &Span::operator=(Span const &other)
{
	if (this != &other)
	{
		_max = other._max;
		_vec = other._vec;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (_vec.size() >= _max)
		throw std::overflow_error("span is full");
	_vec.push_back(n);
}

int Span::shortestSpan() const
{
	if (_vec.size() < 2)
		throw std::logic_error("not enough numbers");

	std::vector<int> sorted(_vec);
	std::sort(sorted.begin(), sorted.end());

	int min = sorted[1] - sorted[0];
	for (size_t i = 1; i < sorted.size() - 1; ++i)
	{
		int diff = sorted[i + 1] - sorted[i];
		if (diff < min)
			min = diff;
	}
	return min;
}

int Span::longestSpan() const
{
	if (_vec.size() < 2)
		throw std::logic_error("not enough numbers");

	int min = *std::min_element(_vec.begin(), _vec.end());
	int max = *std::max_element(_vec.begin(), _vec.end());
	return max - min;
}
