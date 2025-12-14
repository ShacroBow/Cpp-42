#include "Brain.hpp"
#include <iomanip>

Brain::Brain()
{
	std::cout << std::left << std::setw(10) << "Brain" << ": Constructed" << std::endl;
}

Brain::Brain(const Brain& brain)
{
	*this = brain;
	std::cout << std::left << std::setw(10) << "Brain" << ": Copied" << std::endl;
}

Brain::~Brain()
{
	std::cout << std::left << std::setw(10) << "Brain" << ": Destructor" << std::endl;
}

Brain	&Brain::operator=(const Brain& brain)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.ideas[i];
	return (*this);
}