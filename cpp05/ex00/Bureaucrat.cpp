#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
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


const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << std::endl;
    return os;
}