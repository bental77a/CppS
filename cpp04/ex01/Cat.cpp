#include "Cat.hpp"

Cat::Cat() : Animal() , brain(new Brain())
{
    this->type = "Cat";
    std::cout << "default contructor : " << type << "created" << std::endl;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "destructor : " << type << "destroyed" << std::endl;
}
Cat::Cat(const Cat& other)
{
	std::cout << "Cat :  Copy contructer called" << std::endl;
    this->type = other.type;
}
Cat& Cat::operator=(const Cat& other)
{
	std::cout << "Cat  : Assignation operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "cat :  is meowing!!" << std::endl;
}