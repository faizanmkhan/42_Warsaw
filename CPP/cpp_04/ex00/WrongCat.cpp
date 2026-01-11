/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 01:09:28 by faikhan           #+#    #+#             */
/*   Updated: 2026/01/01 01:14:59 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("wCat")
{
    std::cout << "WrongCat default constructor called" << std::endl;
    return ;
}


WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    return ;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout << "Assignment operator called" << std::endl;
    if(this != &other)
        WrongAnimal::operator=(other);
    return (*this);
}
void WrongCat::makeSound() const {
    std::cout << "WrongCat sound: Moo..." << std::endl; 
}

WrongCat::~WrongCat(void)
{
    std::cout << "Destructor called" << std::endl;
    return ;
}

