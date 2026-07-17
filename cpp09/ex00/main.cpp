#include <iostream>
#include <exception>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << std::endl;
		return 1;
	}

	BitcoinExchange btc;
	try
	{
		btc.loadDatabase("data.csv");
	}
	catch (std::exception const &e)
	{
		std::cerr << "Error loading database: " << e.what() << std::endl;
		return 1;
	}

	btc.evaluate(argv[1]);
	return 0;
}
