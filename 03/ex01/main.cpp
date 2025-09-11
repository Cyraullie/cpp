/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:56:43 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/11 14:30:55 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main()
{
	ClapTrap a("Clappy");
	a.attack("enemy1");

	std::cout << "----------------------" << std::endl;

	ScavTrap b("Scrappy");
	b.attack("enemy2");
	b.guardGate();

	return 0;
}
