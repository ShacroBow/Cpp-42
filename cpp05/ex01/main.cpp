#include <cstdlib>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		// ---- Form Constructor exceptions ----
		{
			// grade to sign too high (0)
			try
			{
				Form a("BadFormHigh", 0, 50);
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
			// grade to sign too low (151)
			try
			{
				Form b("BadFormLow", 151, 50);
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
			// grade to execute too high (0)
			try
			{
				Form c("BadExecHigh", 50, 0);
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
			// grade to execute too low (151)
			try
			{
				Form d("BadExecLow", 50, 151);
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
			// valid form
			try
			{
				Form e("ValidForm", 50, 30);
				std::cout << e << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		// ---- Default Form + heap ----
		{
			Form *heapForm = new Form;
			std::cout << "heapForm: " << *heapForm << std::endl;
			delete heapForm;
		}
		std::cout << std::endl;
		// ---- Copy constructor ----
		{
			Form original("TaxForm", 40, 80);
			Form copy(original);
			std::cout << "original:-------\n" << original << std::endl;
			std::cout << "copy:------\n" << copy << std::endl;
		}
		std::cout << std::endl;
		std::cout << std::endl;
		std::cout << std::endl;

		// ---- beSigned: success ----
		{
			std::cout << "________________" << std::endl;
			Form taxForm("signableForm", 50, 100);
			Bureaucrat alice("Alice", 40);
			std::cout << taxForm << std::endl;
			std::cout << alice << std::endl;
			try
			{
				taxForm.beSigned(alice);
				std::cout << "After signing: " << taxForm << std::endl;
			}
			catch (std::exception &e)
			{
				std::cout << "exception: " << e.what() << std::endl;
			}
		}
		std::cout << std::endl;

		// ---- beSigned: failure (grade too low) ----
		{
			std::cout << "________________" << std::endl;
			Form topSecret("unsignableform", 1, 1);
			Bureaucrat bob("Bob", 150);
			std::cout << topSecret << std::endl;
			std::cout << bob << std::endl;
			try
			{
				topSecret.beSigned(bob);
				std::cout << "After signing: " << topSecret << std::endl;
			}
			catch (Form::GradeTooLowException &e)
			{
				std::cout << "exception: " << e.what() << std::endl << std::endl;
			}
		}
		std::cout << std::endl;

		// ---- signForm: success message ----
		{
			std::cout << "________________" << std::endl;
			Form permit("BuildPermit", 100, 50);
			Bureaucrat charlie("Charlie", 50);
			std::cout << permit << std::endl;
			charlie.signForm(permit);
			std::cout << permit << std::endl;
		}
		std::cout << std::endl;

		// ---- signForm: failure message ----
		{
			std::cout << "________________" << std::endl;
			Form classified("ClassifiedDoc", 1, 1);
			Bureaucrat dave("Dave", 150);
			std::cout << classified << std::endl;
			dave.signForm(classified);
			std::cout << classified << std::endl;
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