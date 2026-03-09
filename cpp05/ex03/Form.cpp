#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("blank page"), _tosign(1) , _toexecute(1), _signed(false)
{
}

Form::Form(std::string name, int tosign, int toexecute): _name(name), _tosign(tosign) , _toexecute(toexecute), _signed(false)
{
	if (_tosign < 1 || _toexecute < 1)
		throw Form::GradeTooHighException();
	if (_tosign > 150 || _toexecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form &copy): _name(copy._name), _tosign(copy._tosign), _toexecute(copy._toexecute), _signed(copy._signed)
{
}

void Form::beSigned(Bureaucrat const &penpusher)
{
	if (penpusher.getGrade() > this->_tosign)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

Form::~Form()
{
}

Form &Form::operator=(const Form &copy)
{
	if (this != &copy)
		this->_signed = copy._signed;
	return *this;
}

int	Form::getToSign() const
{
	return this->_tosign;
}

int	Form::getToExec() const
{
	return this->_toexecute;
}

const std::string	&Form::getName() const
{
	return this->_name;
}

bool	Form::getState() const
{
	return this->_signed;
}

int	Form::getGradeToSign() const
{
	return this->_tosign;
}

int	Form::getGradeToExecute() const
{
	return this->_toexecute;
}

bool	Form::getSigned() const
{
	return this->_signed;
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return "Form exception: grade too high";
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return "Form exception: grade too low";
}

const char	*Form::NotSignedException::what() const throw()
{
	return "Form exception: form is not signed";
}

std::ostream &operator<<(std::ostream &o, const Form &f)
{
	o << "Form\t\"" << f.getName() << "\"\n\tsigned: " << (f.getState() ? std::string("true") : std::string("false"))
		<< "\n\tgrade to sign: " << f.getToSign()
		<< "\n\tgrade to execute: " << f.getToExec() << std::endl;
	return o;
}