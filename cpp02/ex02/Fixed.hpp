#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed//fsd
{
	private:
		int _value;
		static const int _fract;
	public:
		Fixed(void);
		Fixed(const int &value);
		Fixed(const float &value);
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy);
		~Fixed();


		int				getRawBits(void) const;
		void			setRawBits(int const raw);
		float			toFloat(void) const;
		int				toInt(void) const;

		//comparison operators
		bool			operator>(const Fixed &other) const;
		bool			operator<(const Fixed &other) const;
		bool			operator>=(const Fixed &other) const;
		bool			operator<=(const Fixed &other) const;
		bool			operator==(const Fixed &other) const;
		bool			operator!=(const Fixed &other) const;
		// arithmetic operators
		Fixed			operator+(const Fixed &other) const;
		Fixed			operator-(const Fixed &other) const;
		Fixed			operator*(const Fixed &other) const;
		Fixed			operator/(const Fixed &other) const;
		// increment and decrement operators
		Fixed			&operator++();
		Fixed			operator++(int);
		Fixed			operator--(int);
		Fixed			&operator--();
		// static member functions
		static			Fixed &min(Fixed &a, Fixed &b);
		static const	Fixed &min(const Fixed &a, const Fixed &b);
		static			Fixed &max(Fixed &a, Fixed &b);
		static const	Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr);


#endif