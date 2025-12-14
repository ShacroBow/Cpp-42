#include "WrongCat.hpp"
#include <iomanip>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << std::left << std::setw(10) << this->_type << ": WrongCat constructed" << std::endl;
}

WrongCat::WrongCat(const WrongCat &wrongCat) : WrongAnimal(wrongCat)
{
	*this = wrongCat;
	std::cout << std::left << std::setw(10) << this->_type << ": WrongCat Copied" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << std::left << std::setw(10) << this->_type << ": WrongCat Destructor" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << std::left << std::setw(10) << this->_type << ": WRONGCAT WRONGCAT WRONGCAT" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& wrongCat)
{
	this->_type = wrongCat.getType();
	return (*this);
}
