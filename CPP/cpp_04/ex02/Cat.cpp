/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 00:08:56 by faikhan           #+#    #+#             */
/*   Updated: 2026/01/01 16:39:01 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Animal.hpp"

Cat::Cat(void) : Animal("Cat")
{
    std::cout << "Cat constructor called" << std::endl;
    _brain = new Brain();
    return ;
}


Cat::Cat(const Cat &other) : Animal(other) {
    std::cout << "Cat copy constructor called" << std::endl;
    this->_type = other._type;
    this->_brain = new Brain(*(other._brain));
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat assignment operator called" << std::endl;
    if(this != &other)
    {
        this->_type = other._type;
        if(this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*other.getBrain());
    }
    return (*this);
}

void Cat::makeSound() const {
    std::cout << "Cat meow: Meow Meow" << std::endl;
}

Brain* Cat::getBrain() const {
    return (this->_brain);
}

Cat::~Cat(void)
{
    std::cout << "Destructor called" << std::endl;
    delete _brain;
    return ;
}

