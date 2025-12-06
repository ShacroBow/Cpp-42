#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class	HumanB
{
	private:
		std::string	_name;
		Weapon		*_weapon; //pointer - when a weapon is optional. because it can be null
	public:
		HumanB(std::string name);
		~HumanB();
		void	attack(void);
		void	setWeapon(Weapon &weapon);
};

#endif
