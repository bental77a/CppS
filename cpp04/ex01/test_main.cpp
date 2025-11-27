#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "=== POLYMORPHISM TEST ===" << std::endl;
    const Animal* animals[4];
    for (int i = 0; i < 4; ++i) {
        if (i < 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    for (int i = 0; i < 4; ++i)
        animals[i]->makeSound();

    for (int i = 0; i < 4; ++i)
        delete animals[i];


    std::cout << "\n=== COPY CONSTRUCTOR / DEEP COPY TEST ===" << std::endl;
    {
        std::cout << "Creating Dog d1" << std::endl;
        Dog d1;                      // has its own Brain
        std::cout << "Copy-constructing Dog d2(d1)" << std::endl;
        Dog d2(d1);                  // should create deep copy of Brain
        std::cout << "Leaving scope (d2 and d1 will be destroyed)" << std::endl;
    }

    std::cout << "\n=== ASSIGNMENT TEST ===" << std::endl;
    {
        Dog d4;
        Dog d5;
        std::cout << "Assigning d5 = d4" << std::endl;
        d5 = d4;                     // operator= should perform deep copy or safe behavior
        std::cout << "Self-assign d5 = d5" << std::endl;
        d5 = d5;                     // should be safe
    }

    std::cout << "\nEnd of tests." << std::endl;
    return 0;
}
