#include <cstdlib>
#include <iostream>
#include <cstdio>
#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
	try
	{
		Data	*original = new Data;

		original->name = "Student";
		original->age = 42;
		original->score = 99.5;

		std::cout << "Original Data:" << std::endl;
		std::cout << "  Address:\t" << original << std::endl;
		std::cout << "  age:\t\t" << original->age << std::endl;
		std::cout << "  score:\t" << original->score << std::endl;
		std::cout << "  name:\t\t" << original->name << std::endl;
		std::cout << std::endl;

		//---------------
		uintptr_t	raw;

		raw = Serializer::serialize(original);
		std::cout << "Serialized (uintptr_t): " << raw << std::endl;
		std::cout << std::endl;

		//------------------
		Data	*restored;

		restored = Serializer::deserialize(raw);
		std::cout << "Deserialized Data:" << std::endl;
		std::cout << "  Address:\t" << restored << std::endl;
		std::cout << "  age:\t\t" << restored->age << std::endl;
		std::cout << "  score:\t" << restored->score << std::endl;
		std::cout << "  name:\t\t" << restored->name << std::endl;
		std::cout << std::endl;

		//---------------------
		std::cout << "Pointers equal: " << (original == restored ? "YES" : "NO") << std::endl;
				
		delete original;
		//done
		
		// const char *str = "heyo";
		// printf("%s\n", str);
		// raw = Serializer::serialize((Data *)str);
		// str = (char *)Serializer::deserialize(raw+2);
		// printf("%s\n", str);
		
	}
	catch (...)
	{
		std::cerr << "error" << std::endl;
	}

	return 0;
}
