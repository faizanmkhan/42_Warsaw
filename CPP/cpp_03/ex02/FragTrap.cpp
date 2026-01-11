/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 21:24:16 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/29 20:14:56 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"


FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    
    setHitPoint(100);
    setEnergyPoint(100);
    setAttackDamage(30);
    std::cout << "FragTrap " << this->getName() << " constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const& other) : ClapTrap(other)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}


FragTrap &FragTrap::operator=(FragTrap const& other)
{
    if(this != &other)
    {
        ClapTrap::operator=(other);
    }
    std::cout << "FragTrap assignment operator called" << std::endl;
    return (*this);
}


FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap destructor called" << std::endl;
    return ;
}
void FragTrap::attack(const std::string& target) {
    if (this->getHitPoint() <= 0)
	{
		std::cout << "FragTrap " << this->getName() << " dead already, cannot attack." << std::endl;
		return ;
	}
	if (this->getEnergyPoint() <=0)
	{
		std::cout << "FragTrap " << this->getName() << " no energy left to attack." << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->getName() << " attacks " << target << " causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	this->setEnergyPoint(this->getEnergyPoint() - 1);
}

void FragTrap::highFivesGuys(void) {
    
    std::cout << "FragTrap " << this->getName() << " give me a HighFive!!!" << std::endl;
}
