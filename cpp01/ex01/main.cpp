#include "Zombie.hpp"

int	main(void)
{
	int	size = 7;
	Zombie	*horde = zombieHorde(size, "Zomby");

	for (int i = 0; i < size; i++)
	{
		horde[i].announce();
	}
	delete [] horde;
}
