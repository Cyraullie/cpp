/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:48:34 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/02 14:33:59 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
	std::cout << GREEN << "Default Ice constructor called" << RESET << std::endl;
}

Ice::Ice(const Ice& cpy): AMateria(cpy._type)
{
	std::cout << LIGHT_GREEN << "Copy Ice constructor called" << RESET << std::endl;
}

Ice::~Ice()
{
	std::cout << RED << "Destructor Ice called" << RESET << std::endl;
}

Ice &Ice::operator=(const Ice& src)
{
	std::cout << LIGHT_GREEN << "Assignment operator for Ice called" << RESET << std::endl;
	if (this != &src)
	{
		this->_type = src._type;
	}
	return (*this);
}

AMateria *Ice::clone() const
{
	return (new Ice());
}

void Ice::use(ICharacter& target)
{
	std::cout << ITALIC << "* shoots an ice bolt at " << target.getName() << " *" << RESET << std::endl;
}