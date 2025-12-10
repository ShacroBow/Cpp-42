#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void)
{
	this->_hp = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string const &name): ClapTrap(name)
{
	this->_hp = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " constructed" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap " << this->_name << " has rapidly disassembled" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &copy): ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &copy)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	ClapTrap::operator=(copy);
	return (*this);
}

void	ScavTrap::attack(std::string const &target)
{
	if (this->_hp <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " is dead, unfortunately it cant attack in the junkyard" << std::endl;
		return;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " cannot attack, ran out of steam" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->_name << " ferociously attacks " << target << ", dealing " << this->_attackDamage << " damage!" << std::endl;
	this->_energyPoints--;
}

void	ScavTrap::guardGate(void)
{
	if (this->_hp <= 0)
		std::cout << "ScavTrap " << this->_name << " cannot enter Gate keeper mode if its DEAD!" << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode!" << std::endl;
}