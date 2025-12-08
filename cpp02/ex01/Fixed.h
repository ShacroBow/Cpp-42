#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int					_value;
		static const int	_fract;
	public:
		Fixed(void);
		Fixed(const int &value);
		Fixed(const float &value);
		Fixed(Fixed const &copy);
		Fixed	&operator=(Fixed const &copy);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream	&operator<<(std::ostream &str, Fixed const &fixed_nbr);

#endif