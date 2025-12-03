#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <exception>
// #include "Bureaucrat.hpp"
#include <ostream>

class Bureaucrat;

class Form
{
private:
    const std::string _name;
    bool _isSigned;
    const int _gradeToSign;
    const int _gradeToExecute;

public:
    Form();
    Form(std::string name, int GradeToSign, int GradeToExecute);
    Form(const Form &other);
	Form &operator=(const Form &other);
    ~Form();

    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;


    void beSigned(Bureaucrat& b);
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
};

std::ostream& operator<<(std::ostream& os, const Form& obj);


#endif