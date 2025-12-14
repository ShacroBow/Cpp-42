#include "Animal.hpp"
#include <iomanip>

Animal::Animal(void)
{
	this->_type = "Default";
	std::cout << std::left << std::setw(10) << this->_type << ": Animal constructed" << std::endl;
}

Animal::Animal(std::string type)
{
	this->_type = type;
	std::cout << std::left << std::setw(10) << this->_type << ": Animal constructed" << std::endl;
}

Animal::Animal(const Animal& rhs)
{
	*this = rhs;
	std::cout << std::left << std::setw(10) << "" << ": Animal Copied" << std::endl;
}

Animal::~Animal()
{
	std::cout << std::left << std::setw(10) << this->_type << ": Animal Destructor" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << std::left << std::setw(10) << this->_type << ": Animal groans" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->_type);
}

Animal	&Animal::operator=(const Animal& animal)
{
	this->_type = animal._type;
	return (*this);
}