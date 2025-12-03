#ifndef ROBOTOMY_REQUEST_FORM_CPP
#define ROBOTOMY_REQUEST_FORM_CPP

#include <iostream>
#include "AForm.hpp"



class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
		virtual void	executeAction() const;
	
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm();
};

#endif