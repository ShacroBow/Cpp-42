#include <cstdlib>
#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	Intern intern;
	Bureaucrat boss("Boss", 1);

	std::cout << "--- valid forms ---" << std::endl;
	{
		AForm *form = intern.makeForm("robotomy request", "Bender");
		if (form)
		{
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
	}
	{
		AForm *form = intern.makeForm("shrubbery creation", "garden");
		if (form)
		{
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
	}
	{
		AForm *form = intern.makeForm("presidential pardon", "Arthur Dent");
		if (form)
		{
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
	}

	std::cout << std::endl << "--- invalid form name ---" << std::endl;
	{
		AForm *form = intern.makeForm("unknown form", "Nobody");
		if (form)
			delete form;
	}

	return EXIT_SUCCESS;
}
