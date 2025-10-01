/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:58:18 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/01 13:37:06 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(): _type("void")
{
	
}

AMateria::AMateria(std::string const & type): _type(type)
{
	
}

AMateria::AMateria(const AMateria& cpy): _type(cpy._type)
{
	
}

AMateria::~AMateria()
{
	
}

AMateria &AMateria::operator=(const AMateria &src)
{
	if (this->_type != src._type)
		this->_type = src._type;
	return (*this);
}


std::string const & AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	(void)target;
}
