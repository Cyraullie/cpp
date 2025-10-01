/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:47:46 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/01 15:52:28 by cgoldens         ###   ########.fr       */
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
	std::cout << "Copy MateriaSource constructor called" << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (this->_materias[i])
		{
			std::cout << "delete materias" << std::endl;
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
		std::cout << "MateriaSource assignment operator called" << std::endl;
		this->_materias[i] = src._materias[i]->clone();
	}
	return (*this);
}
//TODO mettre du dialog
void MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
	{
		std::cout << "invalid materia ! " << std::endl;
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
			std::cout << this->_materias[i]->getType() << " created !" << std::endl;
			return (this->_materias[i]->clone());
		}
	}
	std::cout << "Materia with the type " << type << "doesn't exist !" << std::endl;
	return (NULL);
}
