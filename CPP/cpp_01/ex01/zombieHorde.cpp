/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:44:57 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/24 19:32:06 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
    
    Zombie *ptrHorde = new Zombie[N];
    for (int i = 0; i < N; i++) {
        ptrHorde[i].setName(name);
    }
    return ptrHorde;
}