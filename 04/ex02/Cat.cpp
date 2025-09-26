/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:10:04 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/26 11:40:49 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat"), _brain(new Brain)
{
	std::cout << "Cat has been created" << std::endl;
}
Cat::Cat(const Cat &cpy): AAnimal(cpy._type), _brain(new Brain)
{
	this->_type = cpy._type;
	for (int i = 0; i < 100; i++)
		this->_brain->addIdea(cpy._brain->getIdea(i));
	std::cout << "Copy Cat constructor called" << std::endl;
}

Cat::~Cat()
{
	delete this->_brain;
	std::cout << "Destructor Cat called" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs)
{
	if (this->_type != rhs._type)
	{
		this->_type = rhs._type;
		for (int i = 0; i < 100; i++)
			this->_brain->addIdea(rhs._brain->getIdea(i));
	}
	std::cout << "Assignment operator for Cat called" << std::endl;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}

Brain &Cat::getBrain()
{
	return (*this->_brain);
}
