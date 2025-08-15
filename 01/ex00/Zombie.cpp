/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 15:39:36 by cgoldens          #+#    #+#             */
/*   Updated: 2025/08/15 11:43:04 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "Zombie.hpp"

Zombie::Zombie(std::string name): _name(name)
{
	std::cout << _name << " created !!" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << _name << " destructed !!" << std::endl;
}


void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
