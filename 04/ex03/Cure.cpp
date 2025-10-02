/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:43:07 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/02 14:34:14 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
	std::cout << GREEN << "Default Cure constructor called" << RESET << std::endl;
}

Cure::Cure(const Cure& cpy): AMateria(cpy._type)
{
	std::cout << LIGHT_GREEN << "Copy Cure constructor called" << RESET << std::endl;
}

Cure::~Cure()
{
	std::cout << RED << "Destructor Cure called" << RESET << std::endl;
}

Cure &Cure::operator=(const Cure& src)
{
	std::cout << LIGHT_GREEN << "Assignment operator for Cure called" << RESET << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

AMateria *Cure::clone() const
{
	return (new Cure());
}

void Cure::use(ICharacter& target)
{
	std::cout << ITALIC << "* heals " << target.getName() << "'s wounds *" << RESET << std::endl;
}
