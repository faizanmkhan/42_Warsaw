/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 21:26:20 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/24 23:42:08 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <iostream>
# include <string>

class Weapon {
    private:
        std::string _type;
    public:
        Weapon(std::string type);
        const std::string& getType( void ) const;
        void setType(std::string set);  
};

#endif