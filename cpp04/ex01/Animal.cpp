#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal : default contructor created" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal : destructor created" << std::endl;
}
Animal::Animal(const Animal& other)
{
    std::cout << "Animal :  Copy contructer called" << std::endl;
    this->type = other.type;
}
Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal  : Assignation operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

void Animal::makeSound() const
{
    std::cout << "Rhamna molok 7ila9a RRRRRRRRRRRRRRRRRRR!!" << std::endl;
}
