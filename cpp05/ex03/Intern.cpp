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

Form	*Intern::createRobotomy(const std::string& target)
{
	return new RobotomyRequestForm(target);
}

Form	*Intern::createShrubbery(const std::string& target)
{
	return new ShrubberyCreationForm(target);
}

Form	*Intern::createPresidential(const std::string& target)
{
	return new PresidentialPardonForm(target);
}

Form	*Intern::makeForm( std::string name, std::string target )
{
	typedef Form* (Intern::*Creator)(const std::string&);
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