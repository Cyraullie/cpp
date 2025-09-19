/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:10:28 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/19 14:38:37 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	this->_brain = new Brain();
	std::cout << "Dog has been created" << std::endl;
}

Dog::Dog(const Dog& cpy) : Animal()
{
	this->_type = cpy._type;
	this->_brain = cpy._brain;
}

Dog &Dog::operator=(const Dog& src)
{
	if (this != &src)
	{
		this->_type = src._type;
		this->_brain = src._brain;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog is dead D:" << std::endl;
	delete(this->_brain);
}

void	Dog::makeSound() const
{
	std::cout << "Ouaf Ouaf" << std::endl;
}