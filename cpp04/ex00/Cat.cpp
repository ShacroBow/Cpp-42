#include "Cat.hpp"
#include <iomanip>

Cat::Cat() : Animal("kitty")
{
	std::cout << std::left << std::setw(10) << this->_type << ": Cat constructed" << std::endl;
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
	*this = cat;
	std::cout << std::left << std::setw(10) << this->_type << ": Cat Copied" << std::endl;
}

Cat::~Cat()
{
	std::cout << std::left << std::setw(10) << this->_type << ": Cat Destructor" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << std::left << std::setw(10) << this->_type << ": Meow Meow :3" << std::endl;
}

Cat	&Cat::operator=(const Cat &cat)
{
	this->_type = cat.getType();
	return (*this);
}