/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:42:27 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/01 15:38:18 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(): ICharacter(), _name("Francois"), _inventory()
{

}
Character::Character(std::string name): ICharacter(), _name(name), _inventory()
{
	
}

Character::Character(const Character& cpy): ICharacter(), _name(cpy._name), _inventory()
{
	for (int i = 0; i < INV_SIZE; i++)
	{
		if (cpy._inventory[i])
			this->_inventory[i] = cpy._inventory[i];
	}
}

Character::~Character()
{
	for (int i = 0; i < INV_SIZE; i++)
	{
		if (this->_inventory[i])
		{
			delete(this->_inventory[i]);
			this->_inventory[i] = NULL;
		}
	}
}

Character &Character::operator=(const Character& src)
{
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
		std::cout << "invalid materia ! " << std::endl;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			std::cout << m->getType() << " equiped in place " << i << " of inventory" << std::endl;
			return ;
		}
	}
	std::cout << "No place left in inventory !" << std::endl;
	delete m;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= INV_SIZE || !this->_inventory[idx])
	{
		//TODO mettre un message
		return ;
	}
	//TODO mettre au sol avant de mettre a NULL
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > 0 && idx < INV_SIZE && this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
		std::cout << "No Materia at this spot" << std::endl;
}
