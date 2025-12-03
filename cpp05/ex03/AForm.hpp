#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
// #include "Bureaucrat.hpp"
#include <ostream>

class Bureaucrat;

class AForm
{
    private:
        const std::string _name;
        bool _isSigned;
        const int _gradeToSign;
        const int _gradeToExecute;

    public:
        AForm();
        AForm(std::string name, int GradeToSign, int GradeToExecute);
        AForm(const AForm &other);
	    AForm &operator=(const AForm &other);
        virtual ~AForm();

        std::string getName() const;
        bool getIsSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        void setSigned(bool isSigned);


        void beSigned(Bureaucrat& b);
        void execute(Bureaucrat const & executor) const;
        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        class FormNotSignedException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        virtual void executeAction() const = 0;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);


#endif