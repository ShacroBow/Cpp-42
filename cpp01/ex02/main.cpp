#include <iostream>
#include <iomanip>

int	main()
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << std::left << std::setw(34) << "Memory address of string: "		<< &string		<< std::endl;
	std::cout << std::left << std::setw(34) << "Memory address in stringPTR: "	<< stringPTR	<< std::endl;
	std::cout << std::left << std::setw(34) << "Memory address of stringREF: "	<< &stringREF	<< std::endl;
	std::cout << std::left << std::setw(34) << "Value of the string: "			<< string		<< std::endl;
	std::cout << std::left << std::setw(34) << "Value pointed to by stringPTR: "<< *stringPTR	<< std::endl;
	std::cout << std::left << std::setw(34) << "Value pointed to by stringREF: "<< stringREF	<< std::endl;
}
