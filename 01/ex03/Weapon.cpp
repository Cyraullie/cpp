/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 15:04:04 by cgoldens          #+#    #+#             */
/*   Updated: 2025/08/26 15:07:52 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): _type(type)
{

}

Weapon::~Weapon()
{

}
std::string Weapon::getType()
{
    return (this->_type);
}

void Weapon::setType(std::string type)
{
    this->_type = type;
}
