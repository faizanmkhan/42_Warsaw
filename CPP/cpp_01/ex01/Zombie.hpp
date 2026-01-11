/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 18:23:02 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/24 19:30:52 by faikhan          ###   ########.fr       */
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
        Zombie();
        Zombie(std::string name);
        ~Zombie( void );
        void setName(std::string name);
        void announce( void );
};

Zombie* zombieHorde( int N, std::string name );

#endif