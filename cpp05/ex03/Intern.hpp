#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"



class Intern
{
	private:
    
	public:
		Intern();
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern();
        AForm *makeForm(const std::string FormName , const std::string Target);

        /*  AForm *makeForm(const std::string FormName , const std::string Target)
            if (FormName.empty())
            -> std::cout << Intern creates << FormName << std::endl;
            else
                throw FormHasNotName();

        */
};

#endif
