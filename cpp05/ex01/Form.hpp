#ifndef FORM_HPP
# define FORM_HPP

# include <exception>
# include <iostream>
# include <string>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		const int			_tosign;
		const int			_toexecute;
		bool				_signed;
	
	public:
		Form();
		Form(std::string name, int tosign, int toexecute);
		Form(const Form &copy);
		~Form();

		Form				&operator=(const Form &copy);
		void				beSigned(Bureaucrat &penpusher);

		int					getToSign() const;
		int					getToExec() const;
		const std::string	&getName() const;
		bool				getState() const;
	
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
};

std::ostream	&operator<<(std::ostream &o, const Form &f);

#endif