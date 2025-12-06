
#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

/*****************Setters*****************/
void	Contact::m_setFirst(std::string str)
{
	this->_firstName = str;
}

void	Contact::m_setLast(std::string str)
{
	this->_lastName = str;
}

void	Contact::m_setNick(std::string str)
{
	this->_nickname = str;
}

void	Contact::m_setPhoneNum(std::string str)
{
	this->_phoneNumber = str;
}

void	Contact::m_setSecret(std::string str)
{
	this->_darkestSecret = str;
}

/*****************Getters*****************/
std::string	Contact::m_getFirst(void) const
{
	return (this->_firstName);
}

std::string	Contact::m_getLast(void) const
{
	return (this->_lastName);
}

std::string	Contact::m_getNick(void) const
{
	return (this->_nickname);
}

std::string	Contact::m_getPhoneNum(void) const
{
	return (this->_phoneNumber);
}

std::string	Contact::m_getSecret(void) const
{
	return (this->_darkestSecret);
}

bool	Contact::m_exists(void) const
{
	if (this->_firstName.length() > 0)
	{
		return (true);
	}
	return (false);
}
