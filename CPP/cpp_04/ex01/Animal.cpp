/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/31 22:46:18 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/31 23:53:35 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Random") {
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string const& type) : _type(type) {
    std::cout << "Animal param constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type) {
    std::cout << "Animal copy constructor called" << std::endl;
    return ;
}

Animal &Animal::operator=(const Animal &other) {
    if(this != &other)
        _type = other._type;
    std::cout << "Assignment operator called" << std::endl;
    return (*this);
}

std::string Animal::getType() const {
    return ("Animal type is: " + this->_type);    
}

void Animal::makeSound() const {
    std::cout << "This is sound from Animal" << std::endl;    
}

Animal::~Animal(void) {
    std::cout << "Animal destructor called" << std::endl;
    return ;
}

