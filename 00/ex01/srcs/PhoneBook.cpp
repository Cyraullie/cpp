/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:36:35 by cgoldens          #+#    #+#             */
/*   Updated: 2025/08/07 14:50:37 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdio>
#include <iostream>
#include <string>
#include <limits>
#include <cctype>

std::string	get_userdata(std::string msg)
{
    std::string user_data;
	while (user_data.empty())
	{
		std::cout << msg;
		std::getline(std::cin, user_data);
		if (std::cin.fail() || std::cin.eof())
			return (user_data);
	}
	return (user_data);
}

bool	check_num(std::string s)
{
	if (s.empty())
		return (0);
	for (long unsigned int i = 0; i < s.length(); i++)
	{
		if (!std::isdigit(s[i]))
			return (0);
	}
	return (1);
}

std::string	get_userdata_num(std::string msg)
{
    std::string user_data;
	while (user_data.empty() || !check_num(user_data))
	{
		std::cout << msg;
		std::getline(std::cin, user_data);
		if (std::cin.fail() || std::cin.eof())
			return (user_data);
		if (!check_num(user_data))
			std::cout << std::endl << "Enter a valid number please !!" << std::endl << std::endl;
	}
	return (user_data);
}

void	PhoneBook::addContact(int id)
{
	if(id < MAX_CONTACTS)
	{
		contacts[id].set_firstName(get_userdata("Enter first name: "));
		contacts[id].set_lastName(get_userdata("Enter last name: "));
		contacts[id].set_nickName(get_userdata("Enter nickname: "));
		contacts[id].set_phoneNumber(get_userdata_num("Enter phone number: "));
		contacts[id].set_darkestSecret(get_userdata("Enter darkest secret: "));		
	}
	//else
	//	contacts[search_oldest_entry(contacts)] = Contact(first_name, last_name, nick_name, phone_number, darkest_secret);
}


void	PhoneBook::searchContact()
{
	
}
