#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("clappy"), _hp(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Claptrap " << this->_name << " Is birthed as a default" << std::endl;
}

ClapTrap::ClapTrap(std::string const &name): _name(name), _hp(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Claptrap " << this->_name << " rolled off the assembly line" << std::endl;

}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Claptrap " << this->_name << " has been scrapped" << std::endl;
}


ClapTrap::ClapTrap(const ClapTrap &copy): _name(copy._name), _hp(copy._hp), _energyPoints(copy._energyPoints), _attackDamage(copy._attackDamage)
{
	std::cout << "Claptrap " << this->_name << " has Been overwritten by " << copy._name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
	std::cout << "Claptrap assigned " << copy._name << std::endl;
	this->_name = copy._name;
	this->_hp = copy._hp;
	this->_energyPoints = copy._energyPoints;
	this->_attackDamage = copy._attackDamage;
	return (*this);
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " please stop its already dead" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " damage!" << std::endl;
	if (amount >= this->_hp)
		this->_hp = 0;
	else
		this->_hp -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hp <= 0)
	{
		std::cout << "ClapTrap " << this->_name << "'s empty shell cant be restored" << std::endl;
		return;
	}
	if (this->_energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " Does not have the energy to repair itself" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " repairs itself, restoring " << amount << " hit points!" << std::endl;
	this->_hp += amount;
	this->_energyPoints--;
}

void	ClapTrap::attack(std::string const &target)
{
	if (this->_hp <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " is dead, unable to act" << std::endl;
		return;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is exhausted cant do anything" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoints--;
}