/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:57:24 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/25 15:06:43 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(): _type("Something")
{
	std::cout << "Animal has been created" << std::endl;
}

Animal::Animal(std::string type): _type(type)
{
	std::cout << "Animal constructor called with the type " << type << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal has been destroyed" << std::endl;	
}

Animal::Animal(const Animal& cpy): _type(cpy._type)
{
	
}

Animal &Animal::operator=(const Animal& src)
{
	if (this != &src)
	{
		_type = src._type;
	}
	return *this;
}

std::string Animal::getType() const
{
	return this->_type;
}

void	Animal::makeSound() const
{
	std::cout << "Some generic Animal sound" << std::endl;
}

// DO NOT USE !!!!!!!!!!

Brain &Animal::getBrain() const
{
	Brain *brain = new Brain;
	return (*brain);
}
