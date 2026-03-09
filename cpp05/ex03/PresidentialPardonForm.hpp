#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public Form
{
private:
	const std::string	target;

	PresidentialPardonForm();

public:
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& src);
	~PresidentialPardonForm();

	PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);
	
	void execute(const Bureaucrat& executor) const;
};

#endif 