/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:56:39 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/24 15:18:44 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("Default"), _hp(10), _energy(10), _damage(0)
{
	std::cout << "Default ClapTrap constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name),  _hp(10), _energy(1), _damage(0)
{
	std::cout << "ClapTrap constructor with name " << name << " called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called for " << this->_name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	this->_name = src.getName();
	this->_hp = src.getHP();
	this->_energy = src.getEnergy();
	this->_damage = src.getDamage();
}

ClapTrap &ClapTrap::operator=(const ClapTrap& cpy)
{
	if (this != &cpy)
	{
		this->_name = cpy.getName();
		this->_hp = cpy.getHP();
		this->_energy = cpy.getEnergy();
		this->_damage = cpy.getDamage();
	}
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_energy <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " try to attacks " << target << std::endl;
		std::cout << "Not enough energy" << std::endl;
		return ;
	}
	if (this->_hp <= 0)
	{
		std::cout << "No hit point ClapTrap " << this->_name << " is out of order" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_damage << " points of damage!" << std::endl;
	this->_energy--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	this->_hp -= amount;
	std::cout << "ClapTrap " << this->_name << " take " << amount << " damage, he have now " << this->_hp << " hp!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " try to repair himself" << std::endl;
		std::cout << "Not enough energy" << std::endl;
		return ;
	}
	if (this->_hp <= 0)
	{
		std::cout << "No hit point ClapTrap " << this->_name << " is out of order" << std::endl;
		return ;
	}
	this->_hp += amount;
	this->_energy--;
	std::cout << "ClapTrap " << this->_name << " repair himself, he regains " << amount << " hit points, he have now " << this->_hp << " hp!" << std::endl;
}

std::string ClapTrap::getName() const
{
	return (this->_name);
}

int ClapTrap::getHP() const
{
	return (this->_hp);
}

int ClapTrap::getEnergy() const
{
	return (this->_energy);
}

int ClapTrap::getDamage() const
{
	return (this->_damage);
}