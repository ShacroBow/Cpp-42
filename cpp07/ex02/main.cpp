#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Array.hpp"

#define MAX_VAL 750

int main(void) {
	try
	{
		std::cout << "Empty array test:" << std::endl;
		Array<int> empty;
		std::cout << "size: " << empty.size() << std::endl;
		try {
			empty[0] = 42;
		} catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << "\nSized array:" << std::endl;
		Array<int> numbers(MAX_VAL);
		
		int *mirror = new int[MAX_VAL];
		
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		for (unsigned int i = 0; i < MAX_VAL; ++i) {
			int const value = std::rand();
			numbers[i] = value;
			mirror[i] = value;
		}
		for (unsigned int i = 0; i < MAX_VAL; ++i) {
			if (mirror[i] != numbers[i]) {
				std::cerr << "Mismatch at " << i << std::endl;
				delete[] mirror;
				return 1;
			}
		}
		std::cout << "All values match." << std::endl;

		{
			Array<int> tmp = numbers;
			Array<int> test(tmp);
			tmp[0] = -999;
			if (numbers[0] == -999) {
				std::cerr << "Copy constructor error." << std::endl;
				delete[] mirror;
				return 1;
			}
		}
		std::cout << "Copy constructor OK." << std::endl;

		{
			Array<int> assigned;
			assigned = numbers;
			assigned[0] = 12345;
			if (numbers[0] == 12345) {
				std::cerr << "Assignment error." << std::endl;
				delete[] mirror;
				return 1;
			}
		}
		std::cout << "Assignment operator OK." << std::endl;

		std::cout << "\nOut of bounds:" << std::endl;
		try {
			numbers[static_cast<unsigned int>(-1)] = 0;
		} catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}
		try {
			numbers[MAX_VAL] = 0;
		} catch (std::exception const &e) {
			std::cerr << e.what() << std::endl;
		}

		std::cout << "\nString array:" << std::endl;
		Array<std::string> strings(3);
		strings[0] = "Hello";
		strings[1] = "C++";
		strings[2] = "Templates";

		for (unsigned int i = 0; i < strings.size(); ++i)
			std::cout << "strings[" << i << "] = " << strings[i] << std::endl;

		std::cout << "size: " << strings.size() << std::endl;

		delete[] mirror;
		return 0;
	}
	catch(...){
		std::cout << "bye" << std::endl;}
}