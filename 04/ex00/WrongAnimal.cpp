/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:38:11 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/12 13:38:25 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal has been created" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal has been destroyed" << std::endl;	
}

WrongAnimal::WrongAnimal(const WrongAnimal& cpy)
{
	type = cpy.type;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal& src)
{
	if (this != &src)
	{
		type = src.type;
	}
	return *this;
}

std::string WrongAnimal::getType() const
{
	return this->type;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "Wrong animal sound" << std::endl;
}
