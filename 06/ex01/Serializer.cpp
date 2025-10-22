/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:26:56 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/22 14:27:25 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << GREEN << "Default Serializer constructor called" << RESET << std::endl;
}

Serializer::Serializer(const Serializer &cpy)
{
	std::cout << BLUE << "Copy Serializer constructor called" << RESET << std::endl;
	(void)cpy;
}

Serializer::~Serializer()
{
std::cout << RED << "Serializer destructor called" << RESET << std::endl;
}

Serializer &Serializer::operator=(const Serializer &src)
{
	(void)src;
	std::cout << LIGHT_BLUE << "Serializer assignment operator called" << RESET << std::endl;
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

