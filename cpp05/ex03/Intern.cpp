#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& src)
{
	*this = src;
}

Intern::~Intern() {}

Intern&	Intern::operator=(const Intern& rhs)
{
	( void ) rhs;
	return (*this);
}

AForm	*Intern::createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

AForm	*Intern::createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::createPresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

AForm	*Intern::makeForm( std::string name, std::string target )
{
	typedef AForm* (Intern::*Creator)(const std::string&);
	std::string formNames[] = {
		"robotomy request",
		"shrubbery creation",
		"presidential pardon"
	};
	Creator creators[] = {
		&Intern::createRobotomy,
		&Intern::createShrubbery,
		&Intern::createPresidential
	};

	for (int i = 0; i < 3; ++i)
	{
		if (!name.compare(formNames[i]))
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*creators[i])(target);
		}
	}

	std::cout << "Intern cannot create " << name << " form" << std::endl;
	return NULL;
}