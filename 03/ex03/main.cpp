/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:56:43 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/24 15:37:35 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main()
{
	std::cout << "Creating a DiamondTrap object..." << std::endl;
	DiamondTrap diamond("Diamou");
	DiamondTrap diamo("Diamo");

	diamond.displayAttributs();
	diamo.displayAttributs();
	diamo.attack("Molon");
	diamo.displayAttributs();
	std::cout << "Assigmement Diamo to diamond" << std::endl;
	diamond = diamo;
	diamond.takeDamage(10);
	diamond.displayAttributs();
	diamond.beRepaired(10);
	diamond.displayAttributs();
	std::cout << "new Diamou :" << std::endl;
	diamond.displayAttributs();
	diamo.whoAmI();
}
