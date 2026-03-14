#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137), target("default")
{}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm", 145, 137), target(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs): AForm(rhs), target(rhs.target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	(void)rhs;
	return *this;
}

void	ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	if (!getSigned())
		throw AForm::NotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();

	std::ofstream file((target + "_shrubbery").c_str());

	file << "                                              ." << std::endl;
	file << "                                   .         ;" << std::endl;
	file << "      .              .              ;%     ;;" << std::endl;
	file << "        ,           ,                :;%  %;" << std::endl;
	file << "         :         ;                   :;%;'     .," << std::endl;
	file << ",.        %;     %;            ;        %;'    ,;" << std::endl;
	file << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
	file << "   %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl;
	file << "    ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
	file << "     `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
	file << "      `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
	file << "         `:%;.  :;bd%;          %;@%;'" << std::endl;
	file << "           `@%:.  :;%.         ;@@%;'" << std::endl;
	file << "             `@%.  `;@%.      ;@@%;" << std::endl;
	file << "               `@%%. `@%%    ;@@%;" << std::endl;
	file << "                 ;@%. :@%%  %@@%;" << std::endl;
	file << "                   %@bd%%%bd%%:;" << std::endl;
	file << "                     #@%%%%%:;;" << std::endl;
	file << "                     %@@%%%::;" << std::endl;
	file << "                     %@@@%(o);  . '" << std::endl;
	file << "                     %@@@o%;:(.,'" << std::endl;
	file << "                 `.. %@@@o%::;" << std::endl;
	file << "                    `)@@@o%::;" << std::endl;
	file << "                     %@@(o)::;" << std::endl;
	file << "                    .%@@@@%::;" << std::endl;
	file << "                    ;%@@@@%::;." << std::endl;
	file << "                   ;%@@@@%%:;;;. \\" << std::endl;
	file << "               ...;%@@@@@%%:;;;;,.. " << std::endl;
	file.close();
}

