/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:47:46 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/02 11:52:26 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): IMateriaSource(), _materias()
{
	std::cout << GREEN << "Default MateriaSource constructor called" << RESET << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& cpy): IMateriaSource(), _materias()
{
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		this->_materias[i] = cpy._materias[i]->clone();
	}
	std::cout << LIGHT_GREEN << "Copy MateriaSource constructor called" << RESET << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (this->_materias[i])
		{
			std::cout << RED << "delete materias" << RESET << std::endl;
			delete(this->_materias[i]);
			this->_materias[i] = NULL;
		}
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource& src)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i])
		{
			delete(this->_materias[i]);
			this->_materias[i] = NULL;
		}
		std::cout << LIGHT_GREEN << "MateriaSource assignment operator called" << RESET << std::endl;
		this->_materias[i] = src._materias[i]->clone();
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
	{
		std::cout << LIGHT_RED << "invalid materia ! " << RESET << std::endl;
		return ;
	}
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (!this->_materias[i])
		{
			this->_materias[i] = materia->clone();
			std::cout << materia->getType() << " stock in spot of MateriaSource number " << i << std::endl;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (this->_materias[i]->getType() == type)
		{
			std::cout << LIGHT_BLUE << this->_materias[i]->getType() << " created !" << RESET << std::endl;
			return (this->_materias[i]->clone());
		}
	}
	std::cout << LIGHT_RED << "Materia with the type " << type << "doesn't exist !" << RESET << std::endl;
	return (NULL);
}
