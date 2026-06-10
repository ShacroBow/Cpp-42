#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "functions.hpp"

int main(void)
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	/*****Pointer Identification*****/
	{
		std::cout << "=== identify(Base*) ===" << std::endl;
		for (int i = 0; i < 5; i++)
		{
			Base	*ptr = generate();

			std::cout << "  => ";
			identify(ptr);
			delete ptr;
		}
		std::cout << std::endl;
	}

	/*****Reference Identification*****/
	{
		std::cout << "=== identify(Base&) ===" << std::endl;
		for (int i = 0; i < 5; i++)
		{
			Base	*ptr = generate();

			std::cout << "  => ";
			identify(*ptr);
			delete ptr;
		}
		std::cout << std::endl;
	}

	/*****Explicit Types*****/
	{
		A	a;
		B	b;
		C	c;

		std::cout << "=== explicit types ===" << std::endl;
		std::cout << "A via pointer:   ";
		identify(&a);
		std::cout << "A via reference: ";
		identify(a);
		std::cout << "B via pointer:   ";
		identify(&b);
		std::cout << "B via reference: ";
		identify(b);
		std::cout << "C via pointer:   ";
		identify(&c);
		std::cout << "C via reference: ";
		identify(c);
	}

	return EXIT_SUCCESS;
}
