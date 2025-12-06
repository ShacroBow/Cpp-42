#include "Harl.hpp"

int	ft_getLevelIndex(std::string level)
{
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
			return (i);
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	Harl	harl;
	int		levelIndex;

	if (argc != 2)
	{
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
		return (1);
	}

	levelIndex = ft_getLevelIndex(argv[1]);
	switch (levelIndex)
	{
		case 0:
			harl.complain("DEBUG");
		case 1:
			harl.complain("INFO");
		case 2:
			harl.complain("WARNING");
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}
