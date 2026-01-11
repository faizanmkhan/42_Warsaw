/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 13:30:21 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/28 15:59:55 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
  ClapTrap clapTrap1("Bob");
  ClapTrap clapTrap2("Enemy");
  
  std::cout << std::endl;
  
  clapTrap1.attack("Enemy");
  clapTrap1.beRepaired(5);
  clapTrap1.takeDamage(3);

  std::cout << std::endl;
  
  clapTrap2.attack("Bob");
  clapTrap2.beRepaired(7);
  clapTrap2.takeDamage(11);

   std::cout << std::endl;
  
  return 0;
}