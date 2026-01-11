/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 13:30:28 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/28 22:36:15 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


ClapTrap::ClapTrap(std::string name)
{
    setName(name);
    setHitPoint(10);
    setEnergyPoint(10);
    setAttackDamage(0);
    std::cout << this->_name << " constructor called" << std::endl;
    return ;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
    return;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if(this != &other)
    {
        this->_name = other._name;
        this->_hitPoint = other._hitPoint;
        this->_energyPoint = other._energyPoint;
        this->_attackDamage = other._attackDamage;
        
    }
    std::cout << this->_name << " assignment operator called." << std::endl;
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if(this->_hitPoint <= 0)
    {
        std::cout << _name << " dead already, cannot attack." << std::endl;
        return;
    }
    if(this->_energyPoint <= 0)
    {
        std::cout << _name << " no energy left to attack." << std::endl;
        return;
    }
    _energyPoint -= 1;
    std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    _hitPoint -= amount;
    if(_hitPoint < 0)
        _hitPoint = 0;
    std::cout << _name << " takes " << amount << " points of damage! Hit points left: " << _hitPoint << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if(_hitPoint <= 0)
    {
        std::cout << _name << " can't be repaired,  it's already dead" << std::endl;
		return ;
    }
    if(_energyPoint <= 0)
    {
        std::cout  << _name << " can't be repaired no energy left." << std::endl;
		return ;
    }
    _hitPoint += amount;
	_energyPoint -= 1;
    std::cout << _name << " is repaired by " << amount << "! Total HP: " << _hitPoint << std::endl;
}

ClapTrap::~ClapTrap(void)
{
    std::cout << this->_name << " destructor called" << std::endl;
    return ;
}

void ClapTrap::setName(std::string name)
{
    this->_name = name;
}
void ClapTrap::setAttackDamage(int attackDamage)
{
    this->_attackDamage = attackDamage;
}

void ClapTrap::setHitPoint(int hitPoint)
{
    this->_hitPoint = hitPoint;
}
void ClapTrap::setEnergyPoint(int energyPoint)
{
    this->_energyPoint = energyPoint;
}
std::string ClapTrap::getName(void) const
{
    return (this->_name);
}

int ClapTrap::getAttackDamage(void) const
{
    return (this->_attackDamage);
}

int ClapTrap::getHitPoint(void) const
{
    return (this->_hitPoint);
}

int ClapTrap::getEnergyPoint(void) const
{
    return (this->_energyPoint);
}
