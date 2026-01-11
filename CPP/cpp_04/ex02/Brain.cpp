/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 13:29:01 by faikhan           #+#    #+#             */
/*   Updated: 2026/01/01 15:02:27 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


Brain::Brain(void)
{
    std::cout << "Brain default constructor called" << std::endl;
    return ;
}


Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    *this = other;
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain assignment operator called" << std::endl;
    if(this == &other)
        return *this;
    for (int i = 0; i < 100; i++)
         this->_idea[i] = other._idea[i];   
    return (*this);
}

void Brain::setIdea(std::string idea, int index) {
    if( index < 0 || index >= 100)
        std::cout << "Invalid index for idea" << std::endl;
    this->_idea[index] = idea;
}

const std::string& Brain::getIdea(int index) const {
    if( index < 0 || index >= 100)
        std::cout << "Invalid index" << std::endl;
    return (this->_idea[index]);
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor called" << std::endl;
    return ;
}

