/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 00:40:16 by faikhan           #+#    #+#             */
/*   Updated: 2026/01/01 01:01:39 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongRandom") {
    std::cout << "WrongAnimal default constructor called" << std::endl;
    return ;
}

WrongAnimal::WrongAnimal(std::string const& type) : _type(type) {
    std::cout << "WrongAnimal param constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout << "Assignment operator called" << std::endl;
    if(this != &other)
        this->_type = other._type;
    return (*this);
}

void WrongAnimal::makeSound() const {
    std::cout << "Sound is from WrongAnimal" << std::endl;
}

std::string WrongAnimal::getType() const {
    return("WrongAnimal type is" + this->_type);
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

