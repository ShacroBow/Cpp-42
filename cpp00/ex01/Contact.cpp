
#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

/*****************Setters*****************/
void	Contact::set_first(std::string str)
{
	this->_firstName = str;
}

void	Contact::set_last(std::string str)
{
	this->_lastName = str;
}

void	Contact::set_nick(std::string str)
{
	this->_nickname = str;
}

void	Contact::set_phoneNum(std::string str)
{
	this->_phoneNumber = str;
}

void	Contact::set_note(std::string str)
{
	this->_note = str;
}

/*****************Getters*****************/
std::string	Contact::get_first(void) const
{
	return (this->_firstName);
}

std::string	Contact::get_last(void) const
{
	return (this->_lastName);
}

std::string	Contact::get_nick(void) const
{
	return (this->_nickname);
}

std::string	Contact::get_phone_num(void) const
{
	return (this->_phoneNumber);
}

std::string	Contact::get_note(void) const
{
	return (this->_note);
}

bool	Contact::exists(void) const
{
	if (this->_firstName.length() > 0)
	{
		return (true);
	}
	return (false);
}
