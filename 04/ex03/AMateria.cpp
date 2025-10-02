/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:58:18 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/02 11:41:56 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(): _type("void")
{
	std::cout << GREEN << "Default AMateria constructor called" << RESET << std::endl;
}

AMateria::AMateria(std::string const &type): _type(type)
{
	std::cout << LIGHT_GREEN << "AMateria constructor called with type: " << ITALIC << type << RESET << std::endl;
}

AMateria::AMateria(const AMateria &cpy): _type(cpy._type)
{
	std::cout << LIGHT_GREEN << "Copy constructor AMateria called" << RESET << std::endl;
}

AMateria::~AMateria()
{
	std::cout << RED << "Destructor AMateria called" << RESET << std::endl;
}

AMateria &AMateria::operator=(const AMateria &src)
{
	if (this->_type != src._type)
		this->_type = src._type;
	std::cout << LIGHT_GREEN << "Assignment operator for AMateria called" << RESET << std::endl;
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
