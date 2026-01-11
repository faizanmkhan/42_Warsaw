/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 23:43:35 by faikhan           #+#    #+#             */
/*   Updated: 2026/01/01 16:28:42 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
    std::cout << "Dog constructor called" << std::endl;
    _brain = new Brain();
    return ;
}


Dog::Dog(const Dog &other)
{
    std::cout << "Dog copy constructor called" << std::endl;
    this->_type = other._type;
    this->_brain = new Brain(*(other._brain));
}

Dog& Dog::operator=(const Dog &other) {
    std::cout << "Assignment operator called" << std::endl;
    if(this != &other)
    {
        this->_type = other._type;
        if(this->_brain)
            delete this->_brain;
        this->_brain = new Brain(*other.getBrain());
    }
    return (*this);
}

void Dog::makeSound() const {
    std::cout << "Dog bark : Whoof, Whoof" << std::endl;
}

Brain* Dog::getBrain() const {
    return (this->_brain);
}

Dog::~Dog(void)
{
    std::cout << "Dog destructor called" << std::endl;
    delete _brain;
    return ;
}

