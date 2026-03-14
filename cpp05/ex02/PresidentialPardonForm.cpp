#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5), target("default")
{}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm( "PresidentialPardonForm", 25, 5 ), target( target )
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src): AForm(src), target(src.target)
{}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	(void)rhs;
	//does nothing
	return *this;
}

void    PresidentialPardonForm::execute(const Bureaucrat& executor) const
{
	if (!getSigned())
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}