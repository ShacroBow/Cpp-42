#include <cstdlib>
#include <iostream>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	// ---- execute before signed: all three forms throw NotSignedException ----
	{
		std::cout << "--- unsigned execute attempts ---" << std::endl;
		Bureaucrat exec("Exec", 1);
		ShrubberyCreationForm sc("garden");
		RobotomyRequestForm rr("Marvin");
		PresidentialPardonForm pp("Arthur");
		exec.executeForm(sc);
		exec.executeForm(rr);
		exec.executeForm(pp);
	}
	std::cout << std::endl;

	// ---- signForm: grade too low to sign ----
	{
		std::cout << "--- signForm: grade too low ---" << std::endl;
		Bureaucrat lowly("Lowly", 150);
		ShrubberyCreationForm sc("park");
		lowly.signForm(sc);
	}
	std::cout << std::endl;

	// ---- ShrubberyCreationForm: sign and execute success ----
	{
		std::cout << "--- ShrubberyCreationForm: success ---" << std::endl;
		Bureaucrat b("Boss", 1);
		ShrubberyCreationForm sc("Bossplant");
		b.signForm(sc);
		b.executeForm(sc);
	}
	std::cout << std::endl;

	// ---- ShrubberyCreationForm: executor grade too low ----
	{
		std::cout << "--- ShrubberyCreationForm: executor grade too low ---" << std::endl;
		Bureaucrat signer("Signer", 145);
		Bureaucrat weakExec("WeakExec", 138);
		ShrubberyCreationForm sc("yard");
		signer.signForm(sc);
		weakExec.executeForm(sc);
	}
	std::cout << std::endl;

	// ---- RobotomyRequestForm: sign and execute twice (50% alternation) ----
	{
		std::cout << "--- RobotomyRequestForm: success 50% ---" << std::endl;
		Bureaucrat b("deus ex", 1);
		RobotomyRequestForm rr("Never asked for this");
		b.signForm(rr);
		b.executeForm(rr);
		b.executeForm(rr);
		b.executeForm(rr);
		b.executeForm(rr);
	}
	std::cout << std::endl;

	// ---- RobotomyRequestForm: executor grade too low ----
	{
		std::cout << "--- RobotomyRequestForm: executor grade too low ---" << std::endl;
		Bureaucrat signer("Signer", 72);
		Bureaucrat weakExec("WeakExec", 46);
		RobotomyRequestForm rr("Fry");
		signer.signForm(rr);
		weakExec.executeForm(rr);
	}
	std::cout << std::endl;

	// ---- PresidentialPardonForm: sign and execute success ----
	{
		std::cout << "--- PresidentialPardonForm: success ---" << std::endl;
		Bureaucrat b("Boss", 1);
		PresidentialPardonForm pp("Emperor");
		b.signForm(pp);
		b.executeForm(pp);
	}
	std::cout << std::endl;

	// ---- PresidentialPardonForm: executor grade too low ----
	{
		std::cout << "--- PresidentialPardonForm: executor grade too low ---" << std::endl;
		Bureaucrat signer("Signer", 25);
		Bureaucrat weakExec("WeakExec", 6);
		PresidentialPardonForm pp("Ford");
		signer.signForm(pp);
		weakExec.executeForm(pp);
	}

	return EXIT_SUCCESS;
}
