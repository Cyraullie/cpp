/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:42:27 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/02 12:01:06 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): ICharacter(), _name("Francois"), _inventory()
{
	std::cout << GREEN << "Default Character constructor called" << RESET << std::endl;
}
Character::Character(std::string name): ICharacter(), _name(name), _inventory()
{
	std::cout << LIGHT_GREEN << "Character constructor called with type: " << ITALIC << name << RESET << std::endl;
}

Character::Character(const Character& cpy): ICharacter(), _name(cpy._name), _inventory()
{
	std::cout << LIGHT_GREEN << "Copy constructor Character called" << RESET << std::endl;
	for (int i = 0; i < INV_SIZE; i++)
	{
		if (cpy._inventory[i])
			this->_inventory[i] = cpy._inventory[i];
	}
}

Character::~Character()
{
	std::cout << RED << "Destructor Character called" << RESET << std::endl;
	for (int i = 0; i < INV_SIZE; i++)
	{
		if (this->_inventory[i])
		{
			std::cout << RED << "delete inventories" << RESET << std::endl;
			delete(this->_inventory[i]);
			this->_inventory[i] = NULL;
		}
	}
}

Character &Character::operator=(const Character& src)
{
	std::cout << LIGHT_GREEN << "Assignment operator for Character called" << RESET << std::endl;
	if (this != &src)
	{
		this->_name = src._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i])
			{
				delete(this->_inventory[i]);
				this->_inventory[i] = NULL;
			}
			if (src._inventory[i])
				this->_inventory[i] = src._inventory[i]->clone();
		}
	}
	return *this;
}
		
std::string const & Character::getName() const
{
	return (this->_name);
}

void Character::equip(AMateria* m)
{
	if (!m)
	{
		std::cout << LIGHT_RED << "invalid materia ! " << RESET << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		std::cout << "TEST " << i << std::endl;
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			std::cout << CYAN << this->_inventory[i]->getType() << " equiped in place " << i << " of inventory" << RESET << std::endl;
			return ;
		}
	}
	std::cout << LIGHT_RED << "No place left in inventory !" << RESET << std::endl;
	delete m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= INV_SIZE || !this->_inventory[idx])
	{
		std::cout << LIGHT_RED << "No Materia to unequip at this spot" << RESET << std::endl;
		return ;
	}
	//TODO mettre au sol avant de mettre a NULL
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < INV_SIZE && this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
		std::cout << LIGHT_RED << "No Materia at this spot" << RESET << std::endl;
}
