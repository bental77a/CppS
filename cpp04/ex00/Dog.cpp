#include "Dog.hpp"


Dog::Dog() : Animal()
{
    this->type = "Dog";
    std::cout << "default contructor : " << type << "has created" << std::endl;
}

Dog::~Dog()
{
    std::cout << "destructor : " << type << "has destroyed" << std::endl;
}
Dog::Dog(const Dog& other)
{
    std::cout << "Dog :  Copy contructer called" << std::endl;
    this->type = other.type;
}
Dog& Dog::operator=(const Dog& other)
{
    if (this != &other)
        this->type = other.type;
    return (*this);
}
void Dog::makeSound() const
{
    std::cout << "dog is barking!!" << std::endl;
}