/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:05:20 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/26 14:10:22 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap(): ClapTrap("Default DiamondTrap_clap_name"),FragTrap(), ScavTrap(), _name("Default DiamondTrap")
{
	this->_hp = 100; // from FragTrap
	this->_damage = 30; // from FragTrap
	std::cout << "Default DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(), ScavTrap(), _name(name)
{
	this->_hp = 100; // from FragTrap
	this->_damage = 30; // from FragTrap
	std::cout << "DiamondTrap constructor called for " << this->_name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src): ClapTrap(src._name + "_clap_name") , FragTrap(), ScavTrap(src._name)
{
	this->_damage = src._damage;
	this->_hp = src._hp;
	this->_energy = src._energy;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "destructor called for" << this->_name << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &cpy)
{
	if (this != &cpy)
	{
		this->_name = cpy._name;
		ClapTrap::_name = cpy._name + "_clap_name";
		this->_damage = cpy._damage;
		this->_hp = cpy._hp;
		this->_energy = cpy._energy;
		std::cout << "Assignment operator DiamdonTrap called for "  << this->_name << std::endl;
	}
	return (*this);
}

void DiamondTrap::whoAmI()
{
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Clap_name: " << ClapTrap::_name << std::endl;
}

void DiamondTrap::displayAttributs()
{
	std::cout << "------------------------" << std::endl;
	std::cout << "DiamondTrap" << std::endl;
	std::cout << "Name: " << this->_name << std::endl;
	std::cout << "Clap_name: " << ClapTrap::_name << std::endl;
	std::cout << "Hit points: " << this->_hp << std::endl;
	std::cout << "Energy points: " << this->_energy << std::endl;
	std::cout << "Attack damage: " << this->_damage << std::endl;
	std::cout << "------------------------" << std::endl;
}
