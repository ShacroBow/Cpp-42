#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(): _name("Penpusher"), _grade(150)
{
	std::cout << this->_name << " tightened his tie and adjusted his glasses." << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name)
{
	if (grade < HIGHEST_GRADE)
	throw Bureaucrat::GradeTooHighException();
	else if (grade > LOWEST_GRADE)
	throw Bureaucrat::GradeTooLowException();
	else
	this->_grade = grade;
	std::cout << this->_name << " got hired." << std::endl;
}
Bureaucrat::Bureaucrat(int grade): _name("Penpusher")
{
	if (grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade = grade;
	std::cout << this->_name << " got hired." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bro): _name(bro._name), _grade(bro._grade)
{
	std::cout << this->_name << " Got cloned" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << this->_name << " left to get coffee." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureau)
{
	if (this != &bureau)
	{
		this->_grade = bureau._grade;
		std::cout << this->_name << " got mentored by " << this->_name << std::endl;
	}
	return *this;
}

const std::string &Bureaucrat::getName() const
{
	return this->_name;
}

int	Bureaucrat::getGrade() const
{
	return this->_grade;
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > LOWEST_GRADE)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < HIGHEST_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade <= 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= 1;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade >= 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade += 1;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat exception: grade too high!";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat exception: grade too low!";
}

void	Bureaucrat::signForm(Form &file)
{
	try
	{
		file.beSigned(*this);
		std::cout << this->_name << " signed " << file.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " couldn't sign " << file.getName()
			<< " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(Form const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->_name << " couldn't execute " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}


std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureau)
{
	os << bureau.getName() << ", bureaucrat grade " << bureau.getGrade();
	return os;
}
