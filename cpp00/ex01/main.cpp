
#include "Phonebook.hpp"
#include <iomanip>

static std::string	ft_strTruncate(std::string str, unsigned long max)
{
	if (str.length() > max)
	{
		str.resize(max - 1);
		str += '.';
	}
	return (str);
}

int	ft_contactList(Contact contacts[8])
{
	std::string	str;
	int			i;

	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	
	i = 0;
	while (i < 8 && contacts[i].m_exists())
	{
		str = (char)('0' + i + 1);
		std::cout << "|" << std::right <<std::setw(10) << ft_strTruncate(str, 10);
		std::cout << "|" << std::right <<std::setw(10) << ft_strTruncate(contacts[i].m_getFirst(), 10);
		std::cout << "|" << std::right <<std::setw(10) << ft_strTruncate(contacts[i].m_getLast(), 10);
		std::cout << "|" << std::right <<std::setw(10) << ft_strTruncate(contacts[i].m_getNick(), 10);
		std::cout << "|" << std::endl;
		i++;
	}
	if (i == 0)
		std::cout << "|         *|         *|         *|         *|" << std::endl;
	std::cout << "|__________|__________|__________|__________|\n" << std::endl;
	return (i);
}

int	main(void)
{
	Phonebook	pb;
	std::string	str;

	
	while (str != "EXIT")
	{	
		std::cout << "\nEnter a command > ";
		std::getline(std::cin, str);
		if (str == "ADD")
			pb.m_add();
		else if(str == "SEARCH")
			pb.m_search();
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return(0);
		}
	}
	return (0);
}
