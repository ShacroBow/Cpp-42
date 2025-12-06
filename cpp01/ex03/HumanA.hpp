#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"

class	HumanA
{
	private:
		std::string	_name;
		Weapon		&_weapon; //reference - guarantees that it cant exist without a weapon. because it cant be null
	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void	attack(void);
		void	setWeapon(Weapon weapon);
};

#endif
