#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _name("blank page"), _tosign(1) , _toexecute(1), _signed(false)
{
}

AForm::AForm(std::string name, int tosign, int toexecute): _name(name), _tosign(tosign) , _toexecute(toexecute), _signed(false)
{
	if (_tosign < 1 || _toexecute < 1)
		throw AForm::GradeTooHighException();
	if (_tosign > 150 || _toexecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm &copy): _name(copy._name), _tosign(copy._tosign), _toexecute(copy._toexecute), _signed(copy._signed)
{
}

void AForm::beSigned(Bureaucrat const &penpusher)
{
	if (penpusher.getGrade() > this->_tosign)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

AForm::~AForm()
{
}

AForm &AForm::operator=(const AForm &copy)
{
	if (this != &copy)
		this->_signed = copy._signed;
	return *this;
}

int	AForm::getToSign() const
{
	return this->_tosign;
}

int	AForm::getToExec() const
{
	return this->_toexecute;
}

const std::string	&AForm::getName() const
{
	return this->_name;
}

bool	AForm::getState() const
{
	return this->_signed;
}

int	AForm::getGradeToSign() const
{
	return this->_tosign;
}

int	AForm::getGradeToExecute() const
{
	return this->_toexecute;
}

bool	AForm::getSigned() const
{
	return this->_signed;
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return "AForm exception: grade too high";
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return "AForm exception: grade too low";
}

const char	*AForm::NotSignedException::what() const throw()
{
	return "AForm exception: form is not signed";
}

std::ostream &operator<<(std::ostream &o, const AForm &f)
{
	o << "AForm\t\"" << f.getName() << "\"\n\tsigned: " << (f.getState() ? std::string("true") : std::string("false"))
		<< "\n\tgrade to sign: " << f.getToSign()
		<< "\n\tgrade to execute: " << f.getToExec() << std::endl;
	return o;
}