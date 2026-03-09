#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <fstream>

class ShrubberyCreationForm : public Form {
private:
	const std::string	target;

	ShrubberyCreationForm();

public:
	ShrubberyCreationForm(const std::string& target);
	ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
	~ShrubberyCreationForm();

	ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& rhs);

	void	execute(const Bureaucrat& executor) const;
};

#endif