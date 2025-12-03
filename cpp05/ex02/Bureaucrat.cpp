#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Default: "), _grade(0)
{

}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    else
    {
        this->_grade = grade;
        std::cout << "Bureaucrat " << _name << "has been  created" << std::endl;
    }
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{

}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat " << getName() << " has been destroyed" << std::endl;
}

std::string Bureaucrat::getName() const {return (_name);}
int Bureaucrat::getGrade() const {return (_grade);}

void Bureaucrat::increment()
{
    if (_grade <= 1)
        throw GradeTooHighException();
    this->_grade--;
}
void Bureaucrat::decrement()
{
    if (_grade >= 150)
        throw GradeTooLowException();
    this->_grade++;
}



//////////////////////////////////////////////////////////
/////////      START OF NEW FUNCTION HERE     ////////////
//////////////////////////////////////////////////////////


void Bureaucrat::executeForm(const AForm &form) const
{ 
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}	
}


void Bureaucrat::signForm(AForm &f)
{
    try {
        f.beSigned(*this);
        std::cout << this->getName() << " signed " << f.getName() << std::endl;
    } catch (const AForm::GradeTooLowException& e) {
        std::cout << this->getName() << " couldn’t sign " << f.getName() << " because " << e.what() << std::endl;
    }
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Bureaucrat grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Bureaucrat grade too low";
}


//////////////////////////////////////////////////////////
//////////      END OF NEW FUNCTION HERE     /////////////
//////////////////////////////////////////////////////////

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b)
{
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << std::endl;
    return os;
}