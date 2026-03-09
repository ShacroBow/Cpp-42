#ifndef INTERN_HPP
#define INTERN_HPP

#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

enum Forms {
	ROBOTOMY,
	SHRUBBERY,
	PRESIDENTIAL
};

class Intern {
private:
	Form	*createRobotomy(const std::string& target);
	Form	*createShrubbery(const std::string& target);
	Form	*createPresidential(const std::string& target);

public:
	Intern();
	Intern(const Intern& src);
	~Intern();

	Intern	&operator=(const Intern& rhs);

	Form	*makeForm(std::string name, std::string target);
};

#endif