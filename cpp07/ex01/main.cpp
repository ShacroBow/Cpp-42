#include <iostream>
#include <string>
#include <cctype>
#include "iter.hpp"

template <typename T>
void triple(T &x) {
	x = x + x + x;
}

template <typename T>
void print(T const &x) {
	std::cout << x << " ";
}

void toggleCase(std::string &s) {
	for (size_t i = 0; i < s.length(); ++i) {
		if (std::isalpha(s[i]))
			s[i] ^= 32;
	}
}

int main(void) {
	int ints[] = {0, 1, 2, 3, 4};

	std::cout << "Original ints: ";
	::iter(ints, 5, print<int const>);
	std::cout << std::endl;

	std::cout << "After triple:  ";
	::iter(ints, 5, triple<int>);
	::iter(ints, 5, print<int const>);
	std::cout << std::endl;

	std::string strs[] = {"Hello", "World", "42"};

	std::cout << "\nOriginal strings: ";
	::iter(strs, 3, print<std::string const>);
	std::cout << std::endl;

	std::cout << "After toggleCase: ";
	::iter(strs, 3, toggleCase);
	::iter(strs, 3, print<std::string const>);
	std::cout << std::endl;
	
	std::cout << "After triple: ";
	::triple(strs[0]);
	std::cout << strs[0];
	std::cout << std::endl;

	int const cints[] = {10, 20, 30};
	std::cout << "\nConst ints: ";
	::iter(cints, 3, print<int const>);
	std::cout << std::endl;

	return 0;
}
