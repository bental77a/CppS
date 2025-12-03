#ifndef SHRUBBERY_CREATION_FORM
#define SHRUBBERY_CREATION_FORM

#include <iostream>
#include "AForm.hpp"



class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
		virtual void	executeAction() const;
	
	public:
	// Constructors
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();

		// exceptions
		class OpenFileExeption : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

#endif