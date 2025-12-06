#include "Zombie.hpp"

int	main(void)
{
	Zombie	*zomby = newZombie("Chunky");
	randomChump("Doofus");
	zomby->announce();
	delete zomby;
}
