#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Span.hpp"

int main(void)
{
	std::cout << "subject test:" << std::endl;
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "\nrange iterator test:" << std::endl;
	std::vector<int> more;
	more.push_back(1);
	more.push_back(2);
	more.push_back(3);
	Span sp2(10);
	sp2.addNumber(more.begin(), more.end());
	std::cout << "shortest: " << sp2.shortestSpan() << std::endl;
	std::cout << "longest: " << sp2.longestSpan() << std::endl;

	std::cout << "\n10000 numbers test:" << std::endl;
	Span big(10000);
	std::srand(std::time(NULL));
	for (int i = 0; i < 10000; ++i)
		big.addNumber(std::rand());
	std::cout << "shortest: " << big.shortestSpan() << std::endl;
	std::cout << "longest: " << big.longestSpan() << std::endl;

	std::cout << "\nerror tests:" << std::endl;
	try
	{
		Span empty(5);
		empty.shortestSpan();
	}
	catch (std::exception const &e)
	{
		std::cout << "empty: " << e.what() << std::endl;
	}

	try
	{
		Span full(1);
		full.addNumber(1);
		full.addNumber(2);
	}
	catch (std::exception const &e)
	{
		std::cout << "full: " << e.what() << std::endl;
	}

	return 0;
}
