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
	AForm	*createRobotomy(const std::string& target);
	AForm	*createShrubbery(const std::string& target);
	AForm	*createPresidential(const std::string& target);

public:
	Intern();
	Intern(const Intern& src);
	~Intern();

	Intern	&operator=(const Intern& rhs);

	AForm	*makeForm(std::string name, std::string target);
};

#endif