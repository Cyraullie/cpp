/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:57:24 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/26 11:38:12 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(): _type("Something")
{
	std::cout << "AAnimal has been created" << std::endl;
}

AAnimal::AAnimal(std::string type): _type(type)
{
	std::cout << "AAnimal constructor called with the type " << type << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal has been destroyed" << std::endl;	
}

AAnimal::AAnimal(const AAnimal& cpy): _type(cpy._type)
{
	
}

AAnimal &AAnimal::operator=(const AAnimal& src)
{
	if (this != &src)
	{
		_type = src._type;
	}
	return *this;
}

std::string AAnimal::getType() const
{
	return this->_type;
}

void	AAnimal::makeSound() const
{
	std::cout << "Some generic AAnimal sound" << std::endl;
}
/*
// DO NOT USE !!!!!!!!!!

Brain &AAnimal::getBrain() const
{
	Brain *brain = new Brain;
	return (*brain);
}
*/
