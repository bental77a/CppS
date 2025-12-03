#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _isSigned(false), _gradeToSign(0), _gradeToExecute(0)
{

}

Form::Form(std::string name, int GradeToSign, int GradeToExecute) 
    : _name(name), _isSigned(false) , _gradeToSign(GradeToSign) , _gradeToExecute(GradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << "Form " << _name << " has been  created" << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{

}

Form &Form::operator=(const Form &other)
{
	_isSigned = other._isSigned;
	return (*this);
}

Form::~Form()
{
    std::cout << "Form " << getName() << " has been destroyed" << std::endl;
}


std::string Form::getName() const {return(this->_name);}
bool Form::getIsSigned() const {return(this->_isSigned);}
int Form::getGradeToSign() const {return(this->_gradeToSign);}
int Form::getGradeToExecute() const {return(this->_gradeToExecute);}


void Form::beSigned(Bureaucrat& b)
{
    if (b.getGrade() <= this->getGradeToSign())
        this->_isSigned = true;
    else
        throw Form::GradeTooLowException();
}


const char* Form::GradeTooHighException::what() const throw() {
    return "Form grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Form grade too low";
}





std::ostream &operator<<(std::ostream &os,  Form const &form)
{
    os << "Name: " << form.getName() << " isSigned: " << form.getIsSigned() << " SignGrade: " << form.getGradeToSign() << " ExecuteGrade: " << form.getGradeToExecute() << std::endl;
    return (os);
}