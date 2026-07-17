#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <iterator>
#include <stdexcept>

class Span
{
	private:
		Span();
		unsigned int _max;
		std::vector<int> _vec;
	public:
		Span(unsigned int n);
		Span(Span const &other);
		Span &operator=(Span const &other);
		~Span();

		void addNumber(int n);

		template <typename Iterator>
		void addNumber(Iterator begin, Iterator end)
		{
			size_t dist = static_cast<size_t>(std::distance(begin, end));
			if (_vec.size() + dist > _max)
				throw std::overflow_error("span is full");
			_vec.insert(_vec.end(), begin, end);
		}

		int shortestSpan() const;
		int longestSpan() const;
};

#endif
