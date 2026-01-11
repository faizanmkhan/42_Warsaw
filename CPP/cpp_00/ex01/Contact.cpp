/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 21:11:27 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/11 22:30:52 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
    return;
}

void Contact::setFirstName(std::string const& firstName) {
    this->_firstName = firstName;
}

void Contact::setLastName(std::string const& lastName) {
    this->_lastName = lastName;
}

void Contact::setNickname(std::string const& nickname) {
    this->_nickname = nickname;
}

void Contact::setPhoneNumber(std::string const& phoneNumber) {
    this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string const& darkestSecret) {
    this->_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const {
    return _firstName;
}

std::string Contact::getLastName() const {
    return _lastName;
}

std::string Contact::getNickname() const {
    return _nickname;
}

std::string Contact::getPhoneNumber() const {
    return _phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return _darkestSecret;
}

Contact::~Contact() {
    return;
}