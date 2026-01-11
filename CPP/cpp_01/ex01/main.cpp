/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 19:20:49 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/24 19:39:49 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {
    int n = 7;
    Zombie *ptr = zombieHorde(n, "pZom");
    for (int i = 0; i < n; ++i) {
        ptr[i].announce();
    }
    delete [] ptr;
    return(0);
}