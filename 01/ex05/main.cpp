/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:16:26 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/02 11:52:53 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(void)
{
	Harl Harl;

	std::cout << "DEBUG: " << std::endl;
	Harl.complain("DEBUG");
	std::cout << "INFO: " << std::endl;
	Harl.complain("INFO");
	std::cout << "WARNING: " << std::endl;
	Harl.complain("WARNING");
	std::cout << "ERROR: " << std::endl;
	Harl.complain("ERROR");
	std::cout << "OTHER: " << std::endl;
	Harl.complain("OTHER");
}