/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 20:44:37 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/21 21:39:58 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <string>
# include <iostream>

class Zombie {
    private:
        std::string _name;
    public:
    Zombie(std::string name);
    ~Zombie(void);
    void announce( void );
};

Zombie *newZombie( std::string name );
void randomChump( std::string name );

#endif 