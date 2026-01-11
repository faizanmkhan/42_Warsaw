/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 19:04:33 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/13 16:44:33 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream> 
# include <iomanip>
# include <limits>
# include "Contact.hpp"

class PhoneBook {
        private:
            Contact _contacts[8];
            int     _index;
            int     _contactCount;
        public:
            PhoneBook();
            ~PhoneBook();
            void    addContact(Contact const& contact);
            void    searchContacts() const;
            void    displayContact(int index) const;
    };

#endif