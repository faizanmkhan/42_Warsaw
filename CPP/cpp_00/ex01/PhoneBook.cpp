/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 21:32:28 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/11 22:31:06 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _index(0), _contactCount(0) {
    return;
}

void PhoneBook::addContact(Contact const& contact) {
    _contacts[_index] = contact;
    _index = (_index + 1) % 8;
    if (_contactCount < 8)
        _contactCount++;
}

void PhoneBook::searchContacts() const {
    std::cout << std::left << std::setw(10) << "Index" << "|"
              << std::left << std::setw(10) << "First Name" << "|"
              << std::left << std::setw(10) << "Last Name" << "|"
              << std::left << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < _contactCount; i++) {
        std::cout << std::left << std::setw(10) << i << "|";
        if(_contacts[i].getFirstName().length() > 10)
            std::cout << std::left << std::setw(10) << _contacts[i].getFirstName().substr(0,9) + ".";
        else
            std::cout << std::left << std::setw(10) << _contacts[i].getFirstName();
        std::cout << "|";
        
        if(_contacts[i].getLastName().length() > 10)
            std::cout << std::left << std::setw(10) << _contacts[i].getLastName().substr(0,9) + ".";
        else
            std::cout << std::left << std::setw(10) << _contacts[i].getLastName();
        std::cout << "|";
        
        if(_contacts[i].getNickname().length() > 10)
            std::cout << std::left << std::setw(10) << _contacts[i].getNickname().substr(0,9) + ".";
        else
            std::cout << std::left << std::setw(10) << _contacts[i].getNickname();
        std::cout << std::endl;
    }
}

void PhoneBook::displayContact(int index) const {
    if (index < 0 || index >= _contactCount) {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    std::cout << "First Name: " << _contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << _contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << _contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << _contacts[index].getDarkestSecret() << std::endl;
}

PhoneBook::~PhoneBook() {
    return;
}