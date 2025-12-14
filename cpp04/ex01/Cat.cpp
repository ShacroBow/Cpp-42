#include "Cat.hpp"
#include <iomanip>

Cat::Cat() : Animal("kitty")
{
	this->_brain = new Brain();
	std::cout << std::left << std::setw(10) << this->_type << ": Cat constructed" << std::endl;
}

Cat::Cat(const Cat& cat) : Animal(cat)
{
	this->_brain = new Brain(*cat._brain);
	std::cout << std::left << std::setw(10) << this->_type << ": Cat Copied" << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << std::left << std::setw(10) << this->_type << ": Cat Destructor" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << std::left << std::setw(10) << this->_type << ": Meow Meow :3" << std::endl;
}

Cat	&Cat::operator=(const Cat &cat)
{
	if (this != &cat)
	{
		this->_type = cat.getType();
		*this->_brain = *cat._brain;
	}
	return (*this);
}

Brain*	Cat::getBrain(void) const
{
	return (this->_brain);
}