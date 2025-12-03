#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <string>

Intern::Intern()
{

}

Intern::Intern(const Intern &other)
{
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return (*this);
}


Intern::~Intern()
{
	
}


AForm *Intern::makeForm(const std::string FormName , const std::string Target)
{
    int i = 0;
	std::string available_forms[] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};

	while (i < 3 && FormName != available_forms[i])
		i++;
	
	switch (i)
	{
	case 0:
		std::cout << "Intern creates " << FormName << std::endl;
		return (new ShrubberyCreationForm(Target));
	case 1:
		std::cout << "Intern creates " << FormName << std::endl;
		return (new RobotomyRequestForm(FormName));
	case 2:
		std::cout << "Intern creates " << FormName << std::endl;
		return (new PresidentialPardonForm (Target));
	default:
		std::cout << "Form is not existing" << std::endl;
		return NULL;
	}
}