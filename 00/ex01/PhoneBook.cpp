/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:36:35 by cgoldens          #+#    #+#             */
/*   Updated: 2025/08/07 13:58:53 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdio>
#include <iostream>
#include <string>
#include <limits>
#include <cctype>

std::string get_userdata(std::string msg)
{
    std::string user_data;
	while (user_data.length() == 0)
	{
		std::cout << msg;
		std::getline(std::cin, user_data);
	}
	return (user_data);
}

void PhoneBook::addContact(int id)
{
	if(id < MAX_CONTACTS)
	{
		contacts[id].set_firstName(get_userdata("Enter first name: "));
		contacts[id].set_lastName(get_userdata("Enter last name: "));
		contacts[id].set_nickName(get_userdata("Enter nickname: "));
		contacts[id].set_phoneNumber(get_userdata("Enter phone number: "));
		contacts[id].set_darkestSecret(get_userdata("Enter darkest secret: "));		
	}
	//else
	//	contacts[search_oldest_entry(contacts)] = Contact(first_name, last_name, nick_name, phone_number, darkest_secret);
}

