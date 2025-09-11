/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:23:50 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/11 14:53:34 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hp = 100;
	_energy = 50;
	_damage = 20;
	std::cout << "Default ScavTrap constructor called for " << this->_name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << this->_name << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->_energy <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " try to attacks " << target << std::endl;
		std::cout << "Not enough energy" << std::endl;
		return ;
	}
	if (this->_hp <= 0)
	{
		std::cout << "No hit point this ScavTrap is KO" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_damage << " points of damage!" << std::endl;
	this->_energy--;
}
