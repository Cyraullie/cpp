/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:10:28 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/26 11:40:55 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
Dog::Dog(): AAnimal("Dog"), _brain(new Brain)
{
	std::cout << "Default Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &cpy): AAnimal(cpy._type), _brain(new Brain)
{
	this->_type = cpy._type;
	for (int i = 0; i < 100; i++)
		this->_brain->addIdea(cpy._brain->getIdea(i));
	std::cout << "Copy Dog constructor called" << std::endl;
}

Dog::~Dog()
{
	delete this->_brain;
	std::cout << "Destructor Dog called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs)
{
	if (this->_type != rhs._type || this->_brain != rhs._brain)
	{
		this->_type = rhs._type;
		for (int i = 0; i < 100; i++)
		{
			this->_brain->addIdea(rhs._brain->getIdea(i));
		}
	}
	std::cout << "Assignment operator for Dog called" << std::endl;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Ouaf Ouaf" << std::endl;
}

Brain &Dog::getBrain()
{
	return (*this->_brain);
}