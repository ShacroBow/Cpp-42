#ifndef FIXED_H
#define FIXED_H

# include <iostream>

class	Fixed
{
	private:
		int					_value;
		static const int	_fract;
	public:
		Fixed(void);
		Fixed(Fixed const &copy);
		~Fixed(void);
		
		Fixed	&operator=(Fixed const &copy);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
