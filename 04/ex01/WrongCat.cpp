/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:36:19 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/12 13:37:53 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat has been created" << std::endl;
}

WrongCat::WrongCat(const WrongCat& cpy) : WrongAnimal()
{
	this->type = cpy.type;
}

WrongCat &WrongCat::operator=(const WrongCat& src)
{
	if (this != &src)
	{
		this->type = src.type;
	}
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat is dead D:" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "Wrong cat sound" << std::endl;
}