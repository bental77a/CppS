#include "RobotomyRequestForm.hpp"
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default target")
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
	*this = other;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this == &other)
	{
		this->setSigned(other.getIsSigned());
		this->_target = other._target;
	}
	return (*this);
}


RobotomyRequestForm::~RobotomyRequestForm()
{
	
}


void RobotomyRequestForm::executeAction() const
{
    std::cout << "drilling noises" << std::endl;

    int n = rand();
    if (n % 2 == 0)
        std::cout << _target << " robotomy succeeded" << std::endl;
    else
        std::cout << _target << " robotomy failed" << std::endl;
}
