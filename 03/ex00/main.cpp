/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:56:43 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/10 16:26:11 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap og("ClapTrap");
	ClapTrap another("UwU");

	og.attack(another.getName());
	another.takeDamage(og.getDamage());
	og.takeDamage(another.getDamage());
	another.beRepaired(10);
	og.beRepaired(2);
	
}
