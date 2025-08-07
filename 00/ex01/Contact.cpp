/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:36:40 by cgoldens          #+#    #+#             */
/*   Updated: 2025/08/07 13:59:43 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Constructors

void Contact::set_firstName(std::string firstName)
{
	this->firstName = firstName;
}

void Contact::set_lastName(std::string lastName)
{
	this->lastName = lastName;
}

void Contact::set_nickName(std::string nickName)
{
	this->nickName = nickName;
}

void Contact::set_phoneNumber(std::string phoneNumber)
{
	this->phoneNumber = phoneNumber;
}

void Contact::set_darkestSecret(std::string darkestSecret)
{
	this->darkestSecret = darkestSecret;
}

std::string Contact::get_firstName()
{
	return (firstName);
}

std::string Contact::get_lastName()
{
	return (lastName);
}

std::string Contact::get_nickName()
{
	return (nickName);
}

std::string Contact::get_phoneNumber()
{
	return (phoneNumber);
}

std::string Contact::get_darkestSecret()
{
	return (darkestSecret);
}
