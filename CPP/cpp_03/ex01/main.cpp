/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 13:30:21 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/28 21:02:46 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "Creating a ClapTrap" << std::endl;
    ClapTrap claptrap("CT");
    claptrap.attack("a bandit");
    claptrap.takeDamage(15);
    claptrap.beRepaired(10);
	
    std::cout << std::endl;

    std::cout << "Creating a ScavTrap" << std::endl;
    ScavTrap scavtrap("ST");
    scavtrap.attack("a thief");
    scavtrap.takeDamage(20);
    scavtrap.beRepaired(5);
    scavtrap.guardGate();
	
    std::cout << std::endl;
    return 0;
}