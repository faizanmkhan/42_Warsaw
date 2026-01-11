/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 13:30:35 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/28 22:35:16 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap
{
    private:
        std::string     _name;
        int    _hitPoint;
        int    _energyPoint;
        int    _attackDamage;
    public:
        
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);
        ~ClapTrap();
        
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount); 
        
        void setName(std::string name);
        void setAttackDamage(int attackDamage);
        void setHitPoint(int hitPoint);
        void setEnergyPoint(int energyPoint);
        
        std::string getName(void) const;
        int getAttackDamage(void) const;
        int getHitPoint(void) const;
        int getEnergyPoint(void) const;
};

#endif

