#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon) //initializer list. foo(bar) =~= type foo = bar;
{
	std::cout << "HumanA " << name << " created with " << weapon.getType() << std::endl;
}

HumanA::~HumanA()
{
	std::cout << "HumanA " << this->_name << " destroyed" << std::endl;
}

void	HumanA::setWeapon(Weapon weapon)
{
	this->_weapon = weapon;
}

void	HumanA::attack(void)
{
	std::cout << this->_name << " attacks with his " << this->_weapon.getType() << std::endl;
}
