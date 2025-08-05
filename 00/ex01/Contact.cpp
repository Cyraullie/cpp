/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:36:40 by cgoldens          #+#    #+#             */
/*   Updated: 2025/08/05 16:14:14 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

// Constructors
Contact::Contact()
{
	firstName = "";
	lastName = "";
}

Contact::Contact(std::string first_name, std::string last_name, std::string nick_name,
		std::string phone_number, std::string darkest_secret)
{
	this->firstName = first_name;
	this->lastName = last_name;
	this->nickName = nick_name;
	this->phoneNumber = phone_number;
	this->darkestSecret = darkest_secret;
}

Contact::~Contact()
{
	
}

