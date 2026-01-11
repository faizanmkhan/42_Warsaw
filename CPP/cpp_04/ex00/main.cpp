/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 22:46:06 by faikhan           #+#    #+#             */
/*   Updated: 2026/01/01 12:25:03 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    {
        const Animal* meta = new Animal();      std::cout << std::endl;
        const Animal* j = new Dog();            std::cout << std::endl;
        const Animal* i = new Cat();            std::cout << std::endl;

        std::cout << j->getType() << std::endl;
        std::cout << i->getType() << std::endl;

        i->makeSound(); 
        j->makeSound(); 
        meta->makeSound(); 

        std::cout << std::endl;

        delete meta;    
        delete j;      
        delete i;      
    }

    {
        const WrongAnimal* meta = new WrongAnimal();      std::cout << std::endl;
        const WrongAnimal* i = new WrongCat();            std::cout << std::endl;

        std::cout << i->getType() << std::endl;

        i->makeSound(); 
        meta->makeSound(); 

        std::cout << std::endl;

        delete meta;    
        delete i;       
    }
    return 0;
}

// int main() {
//     const Animal* meta = new Animal();
//     const Animal* j = new Dog();
//     const Animal* i = new Cat();
//     std::cout << j->getType() << " " << std::endl;
//     std::cout << i->getType() << " " << std::endl;
//     i->makeSound(); //will output the cat sound!
//     j->makeSound();
//     meta->makeSound();
//     const WrongAnimal* metaw = new WrongAnimal();
//     const WrongAnimal* iw = new WrongCat();
//     metaw->makeSound();
//     iw->makeSound(); 
//     delete metaw;
//     delete iw;
//     delete meta;  
//     delete j;     
//     delete i;     
//     return 0;
// }