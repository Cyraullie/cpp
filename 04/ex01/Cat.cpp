/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:10:04 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/12 13:13:06 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	std::cout << "Cat has been created" << std::endl;
}

Cat::Cat(const Cat& cpy) : Animal()
{
	this->type = cpy.type;
}

Cat &Cat::operator=(const Cat& src)
{
	if (this != &src)
	{
		this->type = src.type;
	}
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat is dead D:" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow Meow" << std::endl;
}