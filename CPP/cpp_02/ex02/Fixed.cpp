/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 01:09:46 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/27 19:52:45 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0) {
    std::cout << "Default constructor called " << this << std::endl;    
}

Fixed::Fixed(int const value) {
    std::cout << "Integer constructor called" << std::endl;
    _rawBits = value << _fractBits;
}

Fixed::Fixed(float const value) {
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(value *(1 << _fractBits));
}

Fixed::Fixed(Fixed const& instance) {
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

int Fixed::toInt(void) const {
    return (_rawBits >> _fractBits);
}

float Fixed::toFloat(void) const {
    return (static_cast<float>(_rawBits) / (1 << _fractBits));
}
Fixed::~Fixed() {
    std::cout << "Distructor called " << this << std::endl;    
}

std::ostream& operator<<(std::ostream& os, Fixed const& fix_nbr) {
    os << fix_nbr.toFloat();
    return (os);
}

bool Fixed::operator>(Fixed const& instance) const {
    return (this->getRawBits() > instance.getRawBits());    
}

bool Fixed::operator<(Fixed const& instance) const {
    return (this->getRawBits() < instance.getRawBits());    
}

bool Fixed::operator<=(Fixed const& instance) const {
    return (this->getRawBits() <= instance.getRawBits());    
}

bool Fixed::operator>=(Fixed const& instance) const {
    return (this->getRawBits() >= instance.getRawBits());    
}

bool Fixed::operator==(Fixed const& instance) const {
    return (this->getRawBits() == instance.getRawBits());    
}

bool Fixed::operator!=(Fixed const& instance) const {
    return (this->getRawBits() != instance.getRawBits());    
}

Fixed Fixed::operator+(Fixed const& instance) const {
    return Fixed (this->toFloat() + instance.toFloat());
}

Fixed Fixed::operator-(Fixed const& instance) const {
    return Fixed (this->toFloat() - instance.toFloat());
}

Fixed Fixed::operator*(Fixed const& instance) const {
    return Fixed (this->toFloat() * instance.toFloat());
}

Fixed Fixed::operator/(Fixed const& instance) const {
    return Fixed (this->toFloat() / instance.toFloat());
}

Fixed& Fixed::operator++() {
    _rawBits += 1;
    return *this;
}

Fixed& Fixed::operator--() {
    _rawBits -= 1;
    return *this;
}

Fixed Fixed::operator++(int) {
   Fixed temp = *this;
   ++(*this);
   return (temp);
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
   --(*this);
   return (temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b ? a : b);
}


Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b ? a : b);
}


Fixed const& Fixed::min(Fixed const& a, Fixed const& b) {
    return (a < b ? a : b);
}

Fixed const& Fixed::max(Fixed const& a, Fixed const& b) {
    return (a > b ? a : b);
}
