#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:44:33 by cedmulle          #+#    #+#             */
/*   Updated: 2024/02/23 17:09:54 by cedmulle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "WrongDog.hpp"

int	main(void)
{
	// std::cout <<  "///// TEST AVEC 2 ANIMALS /////" << std::endl;
	// std::cout <<  "// ANIMAL CONSTRUCTORS" << std::endl;
	// Animal	a1;
	// Animal	a2(a1);
	// std::cout <<  "// ANIMAL MAKESOUND" << std::endl;
	// a1.makeSound();
	// a2.makeSound();

	// std::cout << std::endl <<  "///// TEST AVEC 2 CAT /////" << std::endl;
	// std::cout <<  "// CAT CONSTRUCTORS" << std::endl;
	// Cat		c1;
	// Cat		c2(c1);
	// std::cout <<  "// CAT MAKESOUND" << std::endl;
	// c1.makeSound();
	// c2.makeSound();

	// std::cout << std::endl <<  "///// TEST AVEC 2 DOG /////" << std::endl;
	// std::cout <<  "// DOG CONSTRUCTORS" << std::endl;
	// Dog		d1;
	// Dog		d2(d1);
	// std::cout <<  "// DOG MAKESOUND" << std::endl;
	// d1.makeSound();
	// d2.makeSound();

	// for (int i = 0; i < 3; i++)
	// 	std::cout << std::endl;
	
	// std::cout <<  "///// TEST AVEC 2 WRONGS ANIMALS /////" << std::endl;
	// std::cout <<  "// WRONG ANIMAL CONSTRUCTORS" << std::endl;
	// WrongAnimal	wa1;
	// WrongAnimal	wa2(wa1);
	// std::cout <<  "// WRONG ANIMAL MAKESOUND" << std::endl;
	// wa1.makeSound();
	// wa2.makeSound();

	// std::cout << std::endl <<  "///// TEST AVEC 2 WRONG CAT /////" << std::endl;
	// std::cout <<  "// WRONG CAT CONSTRUCTORS" << std::endl;
	// WrongCat		wc1;
	// WrongCat		wc2(wc1);
	// std::cout <<  "// WRONG CAT MAKESOUND" << std::endl;
	// wc1.makeSound();
	// wc2.makeSound();

	// std::cout << std::endl <<  "///// TEST AVEC 2 WRONG DOG /////" << std::endl;
	// std::cout <<  "// WRONG DOG CONSTRUCTORS" << std::endl;
	// WrongDog		wd1;
	// WrongDog		wd2(wd1);
	// std::cout <<  "// WRONG DOG MAKESOUND" << std::endl;
	// wd1.makeSound();
	// wd2.makeSound();

	// for (int i = 0; i < 3; i++)
	// 	std::cout << std::endl;

	// std::cout << std::endl <<  "///// BRAIN TESTS /////" << std::endl;

	Brain	b1;
	Brain	b2(b1);
	Brain	b3;
	b3 = b1;



	std::cout << std::endl <<  "///// ALL DESTRUCTORS /////" << std::endl;
	return (0);
}


// int main()
// {
// const Animal* meta = new Animal();
// const Animal* j = new Dog();
// const Animal* i = new Cat();
// std::cout << j->getType() << " " << std::endl;
// std::cout << i->getType() << " " << std::endl;
// i->makeSound(); //will output the cat sound!
// j->makeSound();
// meta->makeSound();
// return 0;
// }