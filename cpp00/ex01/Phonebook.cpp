#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	this->_idx = 0;
	std::cout << "Welcome to phonebook app: these are the legal instructions\n" << std::endl;
	std::cout << "\tADD:\tsave a new contact" << std::endl;
	std::cout << "\tSEARCH:\tdisplay a specific contact" << std::endl;
	std::cout << "\tEXIT" << std::endl << std::endl;
}

Phonebook::~Phonebook(void)
{
	std::cout << "Bye." << std::endl;
}

void	Phonebook::m_add(void)
{
	std::string	str = "";
	int			current_idx;
	
	if (this->_idx >= 8)
	{
		std::cout << "Warning: phonebook is full. Removing oldest contact." << std::endl;
		for (int i = 0; i < 7; i++)
		{
			this->_contacts[i] = this->_contacts[i + 1];
		}
		current_idx = 7;
	}
	else
	{
		current_idx = this->_idx;
	}
	
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << std::setw(27) << std::left << "Enter the first name:";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[current_idx].m_setFirst(str); 
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << std::setw(27) << std::left 
		<< ("Enter " + this->_contacts[current_idx].m_getFirst() + "'s last name: ");
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[current_idx].m_setLast(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << std::setw(27) << std::left 
		<< ("Enter " + this->_contacts[current_idx].m_getFirst() + "'s nickname: "); 
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[current_idx].m_setNick(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << std::setw(27) << std::left 
		<< ("Enter " + this->_contacts[current_idx].m_getFirst() + "'s phone number: ");
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[current_idx].m_setPhoneNum(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << std::setw(27) << std::left 
		<< ("Enter " + this->_contacts[current_idx].m_getFirst() + "'s darkest secret: ");
		if (std::getline(std::cin, str) && str != "")
		{
			this->_contacts[current_idx].m_setSecret(str);
			std::cout << this->_contacts[current_idx].m_getFirst() 
			<< " successfully added to phonebook [" << (current_idx + 1) << "/8]" << std::endl;
		}
	}
	this->_idx++;
}

void	Phonebook::m_search(void)
{
	std::string	str;
	int			max_idx;

	if (this->_idx < 8)
		max_idx = this->_idx;
	else
		max_idx = 8;

	if (!ft_contactList(this->_contacts))
		return;
	while (!std::cin.eof())
	{
		std::cout << "Select an index: ";
		if (std::getline(std::cin, str) && str != "")
		{
			if (str.size() == 1 && str[0] >= '1' && str[0] < ('0' + max_idx + 1) && \
					this->_contacts[str[0] - 1 - '0'].m_exists())
				break ;
		}
		if (str != "")
			std::cout << "Invalid index!" << std::endl;
	}
	if (!std::cin.eof())
		this->m_print(this->_contacts[str[0] - 1 - '0']);
}

void	Phonebook::m_print(Contact contact)
{
	std::cout << std::endl << "Requesting contact information..." << std::endl;
	if (!contact.m_exists())
	{
		std::cout << "Failed to get info for this contact" << std::endl;
		return ;
	}
	std::cout << std::setw(15) << std::left << "First Name:" << contact.m_getFirst() << std::endl;
	std::cout << std::setw(15) << std::left << "Last Name:" << contact.m_getLast() << std::endl;
	std::cout << std::setw(15) << std::left << "Nickname:" << contact.m_getNick() << std::endl;
	std::cout << std::setw(15) << std::left << "Phone Number:" << contact.m_getPhoneNum() << std::endl;
	std::cout << std::setw(15) << std::left << "Darkest secret:" << contact.m_getSecret() << std::endl;
}


static std::string	ft_strTruncate(std::string str, unsigned long max = 10)
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
		std::cout << "|" << std::right <<std::setw(10) << ft_strTruncate(str);
		std::cout << "|" << std::right <<std::setw(10) << ft_strTruncate(contacts[i].m_getFirst());
		std::cout << "|" << std::right <<std::setw(10) << ft_strTruncate(contacts[i].m_getLast());
		std::cout << "|" << std::right <<std::setw(10) << ft_strTruncate(contacts[i].m_getNick());
		std::cout << "|" << std::endl;
		i++;
	}
	if (i == 0)
		std::cout << "|         *|         *|         *|         *|" << std::endl;
	std::cout << "|__________|__________|__________|__________|\n" << std::endl;
	return (i);
}