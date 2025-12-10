#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap: public ScavTrap, public FragTrap
{
	private:
		std::string	_name;
	public:
		DiamondTrap(void);
		DiamondTrap(std::string const &name);
		DiamondTrap(DiamondTrap const &copy);
		virtual ~DiamondTrap(void);

		DiamondTrap	&operator=(DiamondTrap const &copy);

		void	whoAmI(void);
		void	attack(std::string const &target);
};

#endif