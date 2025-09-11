/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:56:43 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/11 13:14:52 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap og("Clap");
	ClapTrap another("Trap");

	og.attack(another.getName());
	another.takeDamage(10);
	another.takeDamage(5);
	og.takeDamage(another.getDamage());
	another.beRepaired(10);
	og.beRepaired(2);
	og.attack(another.getName());
	
}
