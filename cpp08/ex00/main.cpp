#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int> v;
	for (int i = 0; i < 20; i += 2)
		v.push_back(i);

	std::vector<int>::iterator f1 = easyfind(v, 8);
	std::cout << "found: " << *f1 << std::endl;
	std::cout << "before:" << f1[-1] << std::endl;
	std::cout << "next:" << *(f1+1) << std::endl;

	try
	{
		easyfind(v, 8);
	}
	catch (std::exception const &e)
	{
		std::cerr << "miss: " << e.what() << std::endl;
	}

	std::list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);

	std::list<int>::iterator f2 = easyfind(l, 20);
	std::cout << "found: " << *f2 << std::endl;

	return 0;
}
