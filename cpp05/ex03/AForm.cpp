#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Default"), _isSigned(false), _gradeToSign(0), _gradeToExecute(0)
{

}

AForm::AForm(std::string name, int GradeToSign, int GradeToExecute) 
    : _name(name), _isSigned(false) , _gradeToSign(GradeToSign) , _gradeToExecute(GradeToExecute)
{
    if (_gradeToSign < 1 || _gradeToExecute < 1)
        throw GradeTooHighException();
    if (_gradeToSign > 150 || _gradeToExecute > 150)
        throw GradeTooLowException();
    std::cout << "AForm " << _name << " has been  created" << std::endl;
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{

}

AForm &AForm::operator=(const AForm &other)
{
	_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm()
{
    std::cout << "AForm " << getName() << " has been destroyed" << std::endl;
}


std::string AForm::getName() const {return(this->_name);}
bool AForm::getIsSigned() const {return(this->_isSigned);}
int AForm::getGradeToSign() const {return(this->_gradeToSign);}
int AForm::getGradeToExecute() const {return(this->_gradeToExecute);}
void AForm::setSigned(bool isSigned)
{
    this->_isSigned = isSigned;
}

void AForm::beSigned(Bureaucrat& b)
{
    if (b.getGrade() <= this->getGradeToSign())
        this->_isSigned = true;
    else
        throw GradeTooLowException();
}


void AForm::execute(Bureaucrat const &executor) const
{
    if (!getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw GradeTooLowException();
    executeAction();
}



const char* AForm::GradeTooHighException::what() const throw() {
    return "AForm grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "AForm grade too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "AForm Not Signed";
}


std::ostream &operator<<(std::ostream &os,  AForm const &Aform)
{
    os << "Name: " << Aform.getName() << " isSigned: " << Aform.getIsSigned() << " SignGrade: " << Aform.getGradeToSign() << " ExecuteGrade: " << Aform.getGradeToExecute() << std::endl;
    return (os);
}