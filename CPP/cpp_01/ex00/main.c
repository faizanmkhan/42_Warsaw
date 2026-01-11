/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 23:18:17 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/22 00:09:13 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
    Zombie Zom("hello");
    Zom.announce();
	Zombie	*nZombie;
	nZombie = newZombie("heapZombie:");
	nZombie->announce();
	delete nZombie;
	randomChump("stackZombie: ");
	return (0);
}