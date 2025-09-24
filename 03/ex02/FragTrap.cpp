/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:22:55 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/24 15:19:43 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("FragTrap default")
{
	std::cout << "Default FragTrap constructor called" << std::endl;
	this->_hp = 100;
	this->_energy = 50;
	this->_damage = 20;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hp = 100;
	this->_energy = 100;
	this->_damage = 30;
	std::cout << "FragTrap constructor called for " << this->_name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << this->_name << std::endl;
}

FragTrap::FragTrap(const FragTrap& src) : ClapTrap(src) {}

FragTrap& FragTrap::operator=(const FragTrap& cpy) {
	ClapTrap::operator=(cpy);
	return *this;
}


void	FragTrap::highFivesGuys(void)
{
	if (this->_energy <= 0)
	{
		std::cout << "FragTrap " << this->_name << " try to request a high five " << std::endl;
		std::cout << "Not enough energy" << std::endl;
		return ;
	}
	if (this->_hp <= 0)
	{
		std::cout << "No hit point FragTrap " << this->_name << " is out of order" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " wants a high five" << std::endl;
}

void	FragTrap::attack(const std::string& target)
{
	if (this->_energy <= 0)
	{
		std::cout << "FragTrap " << this->_name << " try to attacks " << target << std::endl;
		std::cout << "Not enough energy" << std::endl;
		return ;
	}
	if (this->_hp <= 0)
	{
		std::cout << "No hit point FragTrap " << this->_name << " is out of order" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " attacks " << target << ", causing " << this->_damage << " points of damage!" << std::endl;
	this->_energy--;
}
