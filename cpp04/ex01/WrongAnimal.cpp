#include "WrongAnimal.hpp"
#include <iomanip>

WrongAnimal::WrongAnimal()
{
	this->_type = "Default";
	std::cout << std::left << std::setw(10) << this->_type << ": WrongAnimal constructed" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type)
{
	this->_type = type;
	std::cout << std::left << std::setw(10) << this->_type << ": WrongAnimal constructed" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wrongAnimal)
{
	*this = wrongAnimal;
	std::cout << std::left << std::setw(10) << "" << ": WrongAnimal Copied" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << std::left << std::setw(10) << this->_type << ": WrongAnimal Destructor" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << std::left << std::setw(10) << this->_type << ": WRONG WRONG WRONG" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->_type);
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal& wrongAnimal)
{
	this->_type = wrongAnimal.getType();
	return (*this);
}
