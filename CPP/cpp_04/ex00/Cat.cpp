/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 00:08:56 by faikhan           #+#    #+#             */
/*   Updated: 2026/01/01 00:24:10 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat(void) : Animal("Cat")
{
    std::cout << "Cat constructor called" << std::endl;
    return ;
}


Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat assignment operator called" << std::endl;
    if(this != &other)
        this->_type = other._type;
    return (*this);
}

void Cat::makeSound() const {
    std::cout << "Cat meow: Meow Meow" << std::endl;
}

Cat::~Cat(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

