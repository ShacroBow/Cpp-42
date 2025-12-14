#include "Dog.hpp"
#include <iomanip>

Dog::Dog() : Animal("Dog")
{
	this->_brain = new Brain();
	std::cout << std::left << std::setw(10) << this->_type << ": Dog constructed" << std::endl;
}

Dog::Dog(const Dog& dog) : Animal(dog)
{
	this->_brain = new Brain(*dog._brain);
	std::cout << std::left << std::setw(10) << "" << ": Dog Copied" << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << std::left << std::setw(10) << this->_type << ": Dog Destructor" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << std::left << std::setw(10) << this->_type << ": Bark bark i'm a dog" << std::endl;
}

Dog&	Dog::operator=(const Dog &dog)
{
	if (this != &dog)
	{
		this->_type = dog.getType();
		*this->_brain = *dog._brain;
	}
	return (*this);
}

Brain*	Dog::getBrain(void) const
{
	return (this->_brain);
}
