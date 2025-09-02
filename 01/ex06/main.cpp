/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:16:26 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/02 12:57:21 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

int	main(int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
	{
		std::cerr << "Please enter one arguements !" << std::endl;
		return (1);
	}
	std::string level = argv[1];

	harl.complain(level);
	/*std::cout << "INFO: " << std::endl;
	harl.complain("INFO");
	std::cout << "WARNING: " << std::endl;
	harl.complain("WARNING");
	std::cout << "ERROR: " << std::endl;
	harl.complain("ERROR");
	std::cout << "OTHER: " << std::endl;
	harl.complain("OTHER");*/
}