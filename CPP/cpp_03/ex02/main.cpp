/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 13:30:21 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/29 20:00:43 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

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

     std::cout << "Creating a FragTrap" << std::endl;
     
    FragTrap fragtrap("miniFT");
	fragtrap.highFivesGuys();
	
	std::cout << std::endl;
	
	FragTrap fragtrap2("bigFT");
	fragtrap2.highFivesGuys();

	std::cout << std::endl;
	
	std::cout << "Thanks for HighFives." << std::endl;
    return 0;
}