/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:47:46 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/01 13:48:38 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(): IMateriaSource(), _materias()
{

}

MateriaSource::MateriaSource(const MateriaSource& cpy): IMateriaSource(), _materias()
{
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		this->_materias[i] = cpy._materias[i]->clone();
	}
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (this->_materias[i])
		{
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
		this->_materias[i] = src._materias[i]->clone();
	}
	return (*this);
}
//TODO mettre du dialog
void MateriaSource::learnMateria(AMateria* materia)
{
	if (!materia)
	{
		return ;
	}
	for (int i = 0; i < MAX_MATERIAS; i++)
	{
		if (!this->_materias[i])
		{
			this->_materias[i] = materia->clone();
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
			return (this->_materias[i]->clone());
		}
	}
	return (NULL);
}
