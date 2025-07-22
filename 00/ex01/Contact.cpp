/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:36:40 by cgoldens          #+#    #+#             */
/*   Updated: 2025/07/22 13:57:30 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(){}

Contact::~Contact(){}

void	set_contact(const std::string &fName, const std::string &lName, const std::string &nick, const std::string &phone, const std::string &secret)
{
	firstName = fName;
	lastName = lName;
	nickname = nick;
	phoneNumber = phone;
	darkestSecret = secret;
}
