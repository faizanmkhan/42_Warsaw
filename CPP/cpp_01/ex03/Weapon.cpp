/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 21:26:17 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/24 23:42:24 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string type) : _type(type) {}

const std::string& Weapon::getType( void ) const {
    return (this->_type);
}

void Weapon::setType(std::string set) {
    this->_type = set;
}