#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(): Form("Robotomy Request Form", 72, 45), target("default")
{}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): Form("Robotomy Request Form", 72, 45), target(target)
{}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src): Form(src), target(src.target)
{}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	(void)rhs;
	return *this;
}

void	RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
	if (!getSigned())
		throw Form::NotSignedException();
	if ( executor.getGrade() > this->getGradeToExecute() )
		throw Form::GradeTooLowException();
	else
	{
		static bool seeded = false;
		if (!seeded)
		{
			std::srand(static_cast<unsigned int>(std::time(NULL)));
			seeded = true;
		}
		std::cout << "* drilling noises *" << std::endl;
		if (std::rand() % 2 == 0)
			std::cout << target << " has been robotomized successfully." << std::endl;
		else
			std::cout << "Robotomy failed on " << target << "." << std::endl;
	}
}