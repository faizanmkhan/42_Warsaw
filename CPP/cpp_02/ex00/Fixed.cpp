/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 01:09:46 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/27 16:30:36 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
    std::cout << "Default constructor called " << this << std::endl;    
}

Fixed::Fixed (Fixed const& instance) {
    std::cout << "Copy constructor called " << this << std::endl;
    *this = instance; 
}

Fixed& Fixed::operator=(Fixed const& instance) {
    std::cout << "Copy assignment operator called " << this << std::endl;
    if (this != &instance)
        this->_rawBits = instance.getRawBits();
    return (*this);
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits method called " << this << std::endl;
    return (this->_rawBits);      
}

void Fixed::setRawBits(int const raw) {
    this->_rawBits = raw;
}

Fixed::~Fixed() {
    std::cout << "Distructor called " << this << std::endl;    
}

