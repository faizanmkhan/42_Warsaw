/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 16:43:54 by faikhan           #+#    #+#             */
/*   Updated: 2026/01/01 16:43:55 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
    protected:
        std::string _idea[100];
    public:
        Brain(void);
        Brain(const Brain& other);
        Brain& operator=(const Brain &other);

        void setIdea(std::string idea, int index);
        const std::string& getIdea(int index) const;
        virtual ~Brain();
};

#endif

