#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->type = "WrongCat";
    std::cout << "default contructor : " << type << "created" << std::endl;
}

WrongCat::~WrongCat()
{
    std::cout << "destructor : " << type << "destroyed" << std::endl;
}
WrongCat::WrongCat(const WrongCat& other)
{
	std::cout << "WrongCat :  Copy contructer called" << std::endl;
    this->type = other.type;
}
WrongCat& WrongCat::operator=(const WrongCat& other)
{
	std::cout << "WrongCat  : Assignation operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

void WrongCat::makeSound() const
{
    std::cout << "Wrongcat :  is meowing!!" << std::endl;
}