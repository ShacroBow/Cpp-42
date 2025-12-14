#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {

	protected:
		std::string	_type;

	public:
		Animal(void);
		Animal(std::string type);
		Animal(const Animal& rhs);
		virtual ~Animal(void);

		virtual void	makeSound(void) const;

		std::string	getType(void) const;

		Animal	&operator=(const Animal &animal);

};

#endif