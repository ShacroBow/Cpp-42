#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	// subject main
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	std::cout << "-----" << std::endl;

	// array of animals, half dogs half cats
	int nb = 6;
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

	// deep copy test
	Dog basic;
	{
		Dog tmp = basic;
	}

	std::cout << "-----" << std::endl;

	// another deep copy with assignment
	Dog a;
	Dog b;
	a = b;

	std::cout << "-----" << std::endl;

	// Brain tests
	std::cout << "Brain deep copy test:" << std::endl;
	Dog dog1;
	dog1.getBrain()->ideas[0] = "I love my owner";
	dog1.getBrain()->ideas[1] = "Let's play fetch";

	Dog dog2 = dog1;
	std::cout << "dog1 idea[0]: " << dog1.getBrain()->ideas[0] << std::endl;
	std::cout << "dog2 idea[0]: " << dog2.getBrain()->ideas[0] << std::endl;

	dog2.getBrain()->ideas[0] = "I modified dog2's brain";
	std::cout << "After modification:" << std::endl;
	std::cout << "dog1 idea[0]: " << dog1.getBrain()->ideas[0] << std::endl;
	std::cout << "dog2 idea[0]: " << dog2.getBrain()->ideas[0] << std::endl;

	return 0;
}