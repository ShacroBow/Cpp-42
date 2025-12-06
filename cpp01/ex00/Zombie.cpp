#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << this->_name << " The Zombie has crawled out of the earth" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << "The Zombie has crumbled back into the earth achieving eternal rest" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
