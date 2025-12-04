#include "Phonebook.hpp"

Phonebook::Phonebook(void)
{
	this->_idx = 0;
	std::cout << "Welcome to phonebook app: these are the legal instructions\n" << std::endl;
	std::cout << "\tADD:\tsave a new contact\n" << std::endl;
	std::cout << "\tSEARCH:\tdisplay a specific contact\n" << std::endl;
	std::cout << "\tEXIT" << std::endl;
}

Phonebook::~Phonebook(void)
{
	std::cout << "Bye." << std::endl;
}

Contact	Phonebook::get_contact(int _idx)
{
	return (this->_contacts[_idx % 8]);
}

void	Phonebook::add(void)
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
		std::cout << "Enter the first name: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[current_idx].set_first(str); 
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->_contacts[current_idx].get_first() \
			<< "'s last name: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[current_idx].set_last(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->_contacts[current_idx].get_first() \
			<< "'s nickname: "; 
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[current_idx].set_nick(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter " << this->_contacts[current_idx].get_first() \
			<< "'s phone number: ";
		if (std::getline(std::cin, str) && str != "")
			this->_contacts[current_idx].set_phoneNum(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter a note about " << this->_contacts[current_idx].get_first() \
			<< ": ";
		if (std::getline(std::cin, str) && str != "")
		{
			this->_contacts[current_idx].set_note(str);
			std::cout << this->_contacts[current_idx].get_first() << \
				" successfully added to phonebook [" << (current_idx + 1) << "/8]" << std::endl;
		}
	}
	if (this->_idx < 8)
		this->_idx++;
}

void	Phonebook::search(void)
{
	std::string	str;
	int			max_idx;

	if (this->_idx < 8)
		max_idx = this->_idx;
	else
		max_idx = 8;

	if (!contact_list(this->_contacts))
		return;
	while (!std::cin.eof())
	{
		std::cout << "Select an index: ";
		if (std::getline(std::cin, str) && str != "")
		{
			if (str.size() == 1 && str[0] >= '1' && str[0] < ('0' + max_idx + 1) && \
					this->_contacts[str[0] - 1 - '0'].exists())
				break ;
		}
		if (str != "")
			std::cout << "Invalid index!" << std::endl;
	}
	if (!std::cin.eof())
		this->print(this->_contacts[str[0] - 1 - '0']);
}

void	Phonebook::print(Contact contact)
{
	std::cout << std::endl << "Requesting contact information..." << std::endl;
	if (!contact.exists())
	{
		std::cout << "Failed to get info for this contact" << std::endl;
		return ;
	}
	std::cout << "First Name:\t" << contact.get_first() << std::endl;
	std::cout << "Last Name:\t" << contact.get_last() << std::endl;
	std::cout << "Nickname:\t" << contact.get_nick() << std::endl;
	std::cout << "Phone Number:\t" << contact.get_phone_num() << std::endl;
	std::cout << "Note:\t\t" << contact.get_note() << std::endl;
}
