/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 01:09:49 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/27 16:25:49 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
    private:
        int _rawBits;
        static const int _fractBits = 8;
    public:
        Fixed();
        Fixed(int const);
        Fixed(float const);
        Fixed(Fixed const&);
        Fixed& operator=(Fixed const&);
        ~Fixed();
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        int toInt( void ) const;
        float toFloat( void ) const;
};

    std::ostream& operator<<(std::ostream&, Fixed const&);


#endif