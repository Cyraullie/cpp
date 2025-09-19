/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:57:24 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/19 14:15:13 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal has been created" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal has been destroyed" << std::endl;	
}

Animal::Animal(const Animal& cpy)
{
	_type = cpy._type;
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
