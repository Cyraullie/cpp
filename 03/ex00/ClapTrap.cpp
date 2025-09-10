/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:56:39 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/10 16:27:43 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name): _name(name),  _hp(10), _energy(10), _damage(0)
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energy == 0)
	{
		std::cout << "Not enough energy" << std::endl;
	}
	if (this->_hp == 0)
	{
		std::cout << "No hit point this ClapTrap is KO" << std::endl;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_damage << " points of damage!" << std::endl;
	this->_energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp == 0)
	{
		std::cout << "No hit point this ClapTrap is KO" << std::endl;
	}
	this->_hp -= amount;
	std::cout << "ClapTrap " << this->_name << " take " << amount << " damage, he have now " << this->_hp << " hp!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy == 0)
	{
		std::cout << "Not enough energy" << std::endl;
	}
	this->_hp += amount;
	this->_energy--;
	std::cout << "ClapTrap " << this->_name << " heal himself " << amount << " points, he have now " << this->_hp << " hp!" << std::endl;
}

std::string ClapTrap::getName()
{
	return (this->_name);
}

int ClapTrap::getDamage()
{
	return (this->_damage);
}