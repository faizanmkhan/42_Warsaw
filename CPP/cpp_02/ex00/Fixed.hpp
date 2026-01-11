/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 01:09:49 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/27 14:41:30 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
    private:
        int _rawBits;
        static const int _fractBits = 8;
    public:
        Fixed();
        Fixed(Fixed const&);
        Fixed& operator=(Fixed const&);
        ~Fixed();
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif