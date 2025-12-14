#include "Dog.hpp"
#include <iomanip>

Dog::Dog() : Animal("Dog")
{
	std::cout << std::left << std::setw(10) << this->_type << ": Dog constructed" << std::endl;
}

Dog::Dog(const Dog& dog) : Animal(dog)
{
	*this = dog;
	std::cout << std::left << std::setw(10) << "" << ": Dog Copied" << std::endl;
}

Dog::~Dog()
{
	std::cout << std::left << std::setw(10) << this->_type << ": Dog Destructor" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << std::left << std::setw(10) << this->_type << ": Bark bark i'm a dog" << std::endl;
}

Dog&	Dog::operator=(const Dog &dog)
{
	this->_type = dog.getType();
	return (*this);
}
