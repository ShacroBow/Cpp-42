
#include "Phonebook.hpp"

static std::string	add_spaces(int n)
{
	std::string	str;
	while(n > 0)
	{
		n--;
		str += " ";
	}
	return (str);
}

static std::string	str_resize(std::string str, unsigned long max)
{
	if (str.length() > max)
	{
		str.resize(max);
		str[str.length() - 1] = '.';
	}
	return (str);
}

int	contact_list(Contact contacts[8])
{
	std::string	str;
	int			i;

	std::cout << "_____________________________________________" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|__________|__________|__________|__________|" << std::endl;
	
	i = 0;
	while (i < 8 && contacts[i].exists())
	{
		str = i + 1 +'0';
		str = str_resize(str, 10);
		std::cout << "|" << add_spaces(10 - str.size()) << str;
		str = str_resize(contacts[i].get_first(), 10);
		std::cout << "|" << add_spaces(10 - str.size()) << str;
		str = str_resize(contacts[i].get_last(), 10);
		std::cout << "|" << add_spaces(10 - str.size()) << str;
		str = str_resize(contacts[i].get_nick(), 10);
		std::cout << "|" << add_spaces(10 - str.size()) << str;
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
			pb.add();
		else if(str == "SEARCH")
			pb.search();
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return(0);
		}
	}
	return (0);
}
