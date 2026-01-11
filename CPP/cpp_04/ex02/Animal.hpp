/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 16:43:49 by faikhan           #+#    #+#             */
/*   Updated: 2026/01/01 16:54:01 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include <string>

class Animal
{
    protected:
        std::string _type;
    public:
        Animal(void);
        Animal(std::string const & type);
        Animal(const Animal& other);
        Animal &operator=(const Animal &other);
        virtual ~Animal();

        virtual void makeSound() const = 0;
        std::string getType() const;
};

#endif

