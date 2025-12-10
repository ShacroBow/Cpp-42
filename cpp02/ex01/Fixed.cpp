#include "Fixed.hpp"

const int Fixed::_fract = 8;

Fixed::Fixed(void): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}	

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_value = copy.getRawBits();
}	

Fixed::Fixed(const int &value): _value(value << _fract)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float &value): _value(roundf(value * (1 << _fract)))
{  
	std::cout << "Float constructor called" << std::endl; 
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}	

Fixed	&Fixed::operator=(Fixed const &copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
	this->_value = copy.getRawBits();
	return (*this);
}	

int	Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)_value / (1 << _fract)); // (1 << _fract) == 256
}

int	Fixed::toInt(void) const
{
	return (_value >> _fract); // turnecates 8 bits
}

std::ostream &operator<<(std::ostream &str, const Fixed &fixed_nbr)
{
	return (str << fixed_nbr.toFloat()); // push float value to out stream
}