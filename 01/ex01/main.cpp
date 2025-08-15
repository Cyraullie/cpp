/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:18:50 by cgoldens          #+#    #+#             */
/*   Updated: 2025/08/15 11:36:38 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie zombie("rodeur");
	Zombie *rampant;

	zombie.announce();
	randomChump("feur");
	rampant = newZombie("rampant");
	rampant->announce();
	delete rampant;
}