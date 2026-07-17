#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>
#include <iterator>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &cont, int n)
{
	typename T::iterator pos = std::find(cont.begin(), cont.end(), n);
	if (pos == cont.end())
		throw std::runtime_error("not found");
	return pos;
}

#endif
