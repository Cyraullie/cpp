/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:58:18 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/01 15:47:34 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(): _type("void")
{
	std::cout << "Default AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type): _type(type)
{
	std::cout << "AMateria constructor called with type: " << type << std::endl;
}

AMateria::AMateria(const AMateria &cpy): _type(cpy._type)
{
	std::cout << "Copy constructor AMateria called" << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "Destructor AMateria called" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &src)
{
	if (this->_type != src._type)
		this->_type = src._type;
	std::cout << "Assignment operator for AMateria called" << std::endl;
	return (*this);
}


std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
	std::cout << "Do nothing on" << std::endl;
}
