#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// Animal is now abstract - this line won't compile
	// const Animal* meta = new Animal();

	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound();
	j->makeSound();

	delete j;
	delete i;

	std::cout << "-----" << std::endl;

	// array test like ex01
	int nb = 4;
	Animal* animals[nb];

	for (int k = 0; k < nb; k++)
	{
		if (k < nb / 2)
			animals[k] = new Dog();
		else
			animals[k] = new Cat();
	}
	for (int k = 0; k < nb; k++)
		delete animals[k];

	std::cout << "-----" << std::endl;

	// deep copy
	Dog basic;
	{
		Dog tmp = basic;
	}

	return 0;
}