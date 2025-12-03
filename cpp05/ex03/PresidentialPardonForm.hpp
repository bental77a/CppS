#ifndef PRESIDENTIAL_PARDON_FORM_CPP
#define PRESIDENTIAL_PARDON_FORM_CPP

#include <iostream>
#include "AForm.hpp"



class PresidentialPardonForm : public AForm
{
	private:
		std::string _target;
		virtual void	executeAction() const;
	
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm();

};

#endif