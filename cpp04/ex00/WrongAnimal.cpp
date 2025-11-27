#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal : default contructor created" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal : destructor created" << std::endl;
}
WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    std::cout << "WrongAnimal :  Copy contructer called" << std::endl;
    this->type = other.type;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
    std::cout << "WrongAnimal  : Assignation operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

void WrongAnimal::makeSound() const
{
    std::cout << "sraghna molok 7ila9a RRRRRRRRRRRRRRRRRRR!!" << std::endl;
}
