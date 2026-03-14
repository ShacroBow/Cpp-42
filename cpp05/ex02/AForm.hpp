#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <iostream>
# include <string>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		const int			_tosign;
		const int			_toexecute;
		bool				_signed;
	
	public:
		AForm();
		AForm(std::string name, int tosign, int toexecute);
		AForm(const AForm &copy);
		virtual ~AForm();

		AForm				&operator=(const AForm &copy);
		void				beSigned(Bureaucrat const &penpusher);
		virtual void		execute(Bureaucrat const &executor) const = 0;

		int					getToSign() const;
		int					getToExec() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		const std::string	&getName() const;
		bool				getState() const;
		bool				getSigned() const;
	
	class GradeTooHighException : public std::exception
	{
		public:
			const char	*what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
		public:
			const char	*what() const throw();
	};
	class NotSignedException : public std::exception
	{
		public:
			const char	*what() const throw();
	};
};

std::ostream	&operator<<(std::ostream &o, const AForm &f);

#endif