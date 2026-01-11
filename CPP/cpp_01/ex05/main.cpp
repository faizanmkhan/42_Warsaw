/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faikhan <faikhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 01:02:35 by faikhan           #+#    #+#             */
/*   Updated: 2025/12/26 01:04:46 by faikhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void) {
    
    Harl harl;
    harl.complain("ERROR");
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("ERROR");
    harl.complain("WARNING");
    harl.complain("INFO");
    harl.complain("TYOSDAS");
    harl.complain("");
    return(0);
}