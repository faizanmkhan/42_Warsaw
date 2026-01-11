/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 18:00:52 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/28 22:21:06 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    setHitPoint(100);
    setEnergyPoint(50);
    setAttackDamage(20);
    std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
    std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "ScavTrap assignment operator called" << std::endl;
    return (*this);
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
    if (this->getHitPoint() <= 0)
	{
		std::cout << "ScavTrap " << this->getName() << " dead already, cannot attack." << std::endl;
		return ;
	}
	if (this->getEnergyPoint() <=0)
	{
		std::cout << "ScavTrap " << this->getName() << " no energy left to attack." << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << " causing " <<this->getAttackDamage()<< " points of damage!" << std::endl;
	this->setEnergyPoint(this->getEnergyPoint() - 1);
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode." << std::endl;
}

