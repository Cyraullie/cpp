/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:36:40 by cgoldens          #+#    #+#             */
/*   Updated: 2025/07/23 13:52:45 by cgoldens         ###   ########.fr       */
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
	firstName = first_name;
	lastName = last_name;
	nickName = nick_name;
	phoneNumber = phone_number;
	darkestSecret = darkest_secret;
}

Contact::~Contact()
{
	
}

