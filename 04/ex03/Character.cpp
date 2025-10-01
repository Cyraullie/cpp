/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:42:27 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/01 11:56:31 by cgoldens         ###   ########.fr       */
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
			delete(this->_inventory[i]);
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
				delete this->_inventory[i];
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

//TODO faire les fonctions en dessous
void Character::equip(AMateria* m)
{
	//TODO verifier quelle case de l'inventaire est pris
}

void Character::unequip(int idx)
{
	
}

void Character::use(int idx, ICharacter& target)
{
	
}
