/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 12:26:38 by faikhan           #+#    #+#             */
/*   Updated: 2026/01/01 16:56:44 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
# include "Brain.hpp"

int main() 
{
    //const Animal* meta = new Animal(); // This line will cause an error
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << std::endl;

    std::cout << "Type of Dog: " << j->getType() << std::endl;
    std::cout << "Tye of Cat: " << i->getType() << std::endl;

    std::cout << std::endl;

    std::cout << "Sound of cat: ";
    i->makeSound();

    std::cout << "Sound of dog: ";
    j->makeSound(); 

    std::cout << std::endl;
    delete j;
    delete i;

    return 0;
}