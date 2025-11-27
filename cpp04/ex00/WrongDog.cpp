#include "WrongDog.hpp"


WrongDog::WrongDog() : WrongAnimal()
{
    this->type = "WrongDog";
    std::cout << "default contructor : " << type << "has created" << std::endl;
}

WrongDog::~WrongDog()
{
    std::cout << "destructor : " << type << "has destroyed" << std::endl;
}
WrongDog::WrongDog(const WrongDog& other)
{
    std::cout << "WrongDog :  Copy contructer called" << std::endl;
    this->type = other.type;
}
WrongDog& WrongDog::operator=(const WrongDog& other)
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}
void WrongDog::makeSound() const
{
    std::cout << "Wrongdog is barking!!" << std::endl;
}