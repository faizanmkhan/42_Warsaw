/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 12:26:38 by faikhan           #+#    #+#             */
/*   Updated: 2026/01/01 16:41:10 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
# include "Brain.hpp"

int main()
{
    const int size = 4;
    Animal *animals[size];

    for (int i = 0; i < size / 2; i++)
        animals[i] = new Dog();
    for (int i = size / 2; i < size; i++)
        animals[i] = new Cat();
    std::cout << std::endl;
    for (int i = 0; i < size; i++)
        animals[i]->makeSound();
    std::cout << std::endl;
    for (int i = 0; i < size; i++)
        delete animals[i];

    std::cout << std::endl;
    std::cout << "\e[1;39mProof that the copies are not shallow\e[0m" << std::endl;
    std::cout << std::endl;
    Dog dog;
    Cat cat;
    
    Dog &dog2 = dog;
    Cat &cat2 = cat;
    std::cout << std::endl;
    std::cout << "\e[1;39m1. Setting ideas in the original brain\e[0m" << std::endl;
    dog2.getBrain()->setIdea("\e[1;39mI am a dog\e[0m", 0);
    cat2.getBrain()->setIdea("\e[1;39mI am a cat\e[0m", 0);
    std::cout << std::endl;
    
    std::cout << "\e[1;39m2. Make a copy of the original dog and cat\e[0m"<< std::endl;
    Dog dog3(dog2);
    Cat cat3(cat2);

    Dog &dog4 = dog3;
    Cat &cat4 = cat3;
    std::cout << std::endl;

    std::cout << "\e[1;39m3. We modify the copy brains\e[0m" << std::endl;
    dog4.getBrain()->setIdea("\e[1;39mI am a dog copy\e[0m", 0);
    cat4.getBrain()->setIdea("\e[1;39mI am a cat copy\e[0m", 0);
    std::cout << std::endl;

    std::cout << "\e[1;39m4. Check if the original brains are the same and different from the copies\e[0m" << std::endl;
    std::cout << "\e[1;39mdog: \e[0m" << dog2.getBrain()->getIdea(0) << std::endl;
    std::cout << "\e[1;39mcat: \e[0m" << cat2.getBrain()->getIdea(0) << std::endl;
    std::cout << "\e[1;39mdog copy: \e[0m" << dog4.getBrain()->getIdea(0) << std::endl;
    std::cout << "\e[1;39mcat copy: \e[0m" << cat4.getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;

return 0;
}