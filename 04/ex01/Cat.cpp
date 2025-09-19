/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:10:04 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/19 14:38:32 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	this->_brain = new Brain();
	std::cout << "Cat has been created" << std::endl;
}

Cat::Cat(const Cat& cpy) : Animal()
{
	this->_type = cpy._type;
	this->_brain = cpy._brain;
}

Cat &Cat::operator=(const Cat& src)
{
	if (this != &src)
	{
		this->_type = src._type;
		this->_brain = src._brain;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat is dead D:" << std::endl;
	delete(this->_brain);
}

void	Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}