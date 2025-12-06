
#include "Phonebook.hpp"

int	main(void)
{
	Phonebook	pb;
	std::string	str;

	while (str != "EXIT" && !std::cin.eof())
	{	
		std::cout << "Enter a command > ";
		std::getline(std::cin, str);
		if (str == "ADD")
			pb.m_add();
		else if(str == "SEARCH")
			pb.m_search();
	}
	if (std::cin.eof())
	{
		std::cout << std::endl;
		return(0);
	}
	return (0);
}
