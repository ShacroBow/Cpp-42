#include <cstdlib>
#include "Bureaucrat.hpp"

// class custom_exception : public std::exception
// {
// 	public:
// 		virtual const char* what() const throw()
// 		{
// 			return "Custom exception.";
// 		}
// };

int main(void)
{
	// try
	// {
	// 	// throw custom_exception();
	// 	throw 5.1f;
	// }
	// catch (float e)//custom_exception &e)
	// {
	// 	std::cout << "custom exception made. " << e << std::endl;
	// }
	try
	{
		{
			// Constructor
			try
			{
				Bureaucrat	a(-1);
			}
			catch(std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
			try
			{
				Bureaucrat	b(151);
			}
			catch(std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}

			{
				try
				{
					Bureaucrat	c(50);
				}
				catch(std::exception &e)
				{
					std::cout << e.what() << std::endl;
				}
			}
			std::cout << std::endl;
			std::cout << std::endl;


			std::cout << "-------lolo--------" << std::endl;

			Bureaucrat	*lolo = new Bureaucrat;
			std::cout << "lolo: " << *lolo << std::endl;
			delete lolo;
			std::cout << "-------lolo--------" << std::endl;
			std::cout << std::endl;

			
			Bureaucrat	bob("Bob", 87);
			Bureaucrat	bob2(bob);

		}
		std::cout << std::endl;
		std::cout << std::endl;

		{
			std::cout <<"________________"<< std::endl;
			try
			{
				Bureaucrat bobo("bobo", 150);
				std::cout << bobo << std::endl;
				bobo.decrementGrade();
			}
			catch (Bureaucrat::GradeTooLowException &e)
			{
				std::cout << "exception :" << e.what() << std::endl << std::endl;
			}
			try
			{
				Bureaucrat dingo("dingo", 1);
				std::cout << dingo << std::endl;
				dingo.incrementGrade();
			}
			catch (Bureaucrat::GradeTooHighException &e)
			{
				std::cout << "exception :" << e.what() << std::endl << std::endl;
			}
		}
		return EXIT_SUCCESS;
	}
	catch (std::exception &e)
	{
		std::string dingo;
		dingo = "wtf: ";
		std::cout << dingo + e.what() << std::endl;
	}
}