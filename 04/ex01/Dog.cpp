/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:10:28 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/12 13:13:50 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	std::cout << "Dog has been created" << std::endl;
}

Dog::Dog(const Dog& cpy) : Animal()
{
	this->type = cpy.type;
}

Dog &Dog::operator=(const Dog& src)
{
	if (this != &src)
	{
		this->type = src.type;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog is dead D:" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Ouaf Ouaf" << std::endl;
}