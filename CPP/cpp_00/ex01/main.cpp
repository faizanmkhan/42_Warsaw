/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 22:21:43 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/13 17:35:48 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main() {
    PhoneBook phoneBook;
    std::string cmd;
    
    while (true)
    {
        std::cout << "Enter command (ADD, SEARCH, EXIT): ";
        if(!std::getline(std::cin, cmd))
        {
            std::cout << std::endl << "EOF detected, Quitting!" << std::endl;
            break;
        }
        if(cmd == "ADD")
        {
            Contact newContact;
            std::string input;
            do
            {
                std::cout << "First Name: ";
                if (!std::getline(std::cin, input))
                {
                    std::cout << std::endl << "EOF detected, Quitting!" << std::endl;
                    return 0;
                }
                if(input.empty())
                    std::cout << "First Name cannot be empty. Please try again." << std::endl;
            }
            while (input.empty());
            newContact.setFirstName(input);
            do
            {
                std::cout << "Last Name: ";
                if (!std::getline(std::cin, input))
                {
                    std::cout << std::endl << "EOF detected, Quitting!" << std::endl;
                    return 0;
                }
                if(input.empty())
                    std::cout << "Last Name cannot be empty. Please try again." << std::endl;
            } while (input.empty());
            newContact.setLastName(input);
            do
            {
                std::cout << "Nickname: ";
                if (!std::getline(std::cin, input))
                {
                    std::cout << std::endl << "EOF detected, Quitting!" << std::endl;
                    return 0;
                }
                if(input.empty())
                    std::cout << "Nickname cannot be empty. Please try again." << std::endl;
            } while (input.empty());
            newContact.setNickname(input);
            do
            {
                std::cout << "Phone Number: ";
                if (!std::getline(std::cin, input))
                {
                    std::cout << std::endl << "EOF detected, Quitting!" << std::endl;
                    return 0;
                }
                if(input.empty())
                    std::cout << "Phone Number cannot be empty. Please try again." << std::endl;
            } while (input.empty());
            newContact.setPhoneNumber(input);
            do
            {
                std::cout << "Darkest Secret: ";
                if (!std::getline(std::cin, input))
                {
                    std::cout << std::endl << "EOF detected, Quitting!" << std::endl;
                    return 0;
                }
                if(input.empty())
                    std::cout << "Darkest Secret cannot be empty. Please try again." << std::endl;
            } while (input.empty());
            newContact.setDarkestSecret(input);
            phoneBook.addContact(newContact);
        }
        else if(cmd == "SEARCH")
        {
            phoneBook.searchContacts();
            std::cout << "Enter index to view details: ";
            int index;
            std::cin >> index;
            if(std::cin.fail() || index < 0 || index >= 8)
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid index. Please entre a valid index number." << std::endl;
            }
            else
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                phoneBook.displayContact(index);
            }
        }
        else if(cmd == "EXIT")
        {
            std::cout << "Exiting program." << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid command. Please enter ADD, SEARCH, or EXIT." << std::endl;
        }
    }
    return 0;
}