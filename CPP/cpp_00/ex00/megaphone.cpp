/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 01:05:00 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/10 23:10:19 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else 
	{
		for (int i = 1; i < ac; ++i)
			for (int j = 0; av[i][j] != '\0'; ++j) 
				std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(av[i][j])));
		std::cout << std::endl;
	}
	return (0);
}