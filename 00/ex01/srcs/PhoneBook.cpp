/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:36:35 by cgoldens          #+#    #+#             */
/*   Updated: 2025/08/08 14:41:32 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <string>
#include <limits>
#include <cctype>

std::string delete_space(std::string s)
{
	int start = 0;
	int end = s.length() - 1;

	while (s[start] == ' ')
	{
		start++;
	}
	while (s[end] == ' ')
	{
		end--;
	}
	end++;
	s = s.substr(start, end);
	return s;
}


std::string	get_userdata(std::string msg)
{
    std::string user_data;
	while (user_data.empty())
	{
		std::cout << msg;
		std::getline(std::cin, user_data);
		if (std::cin.fail() || std::cin.eof())
		{
			user_data == delete_space(user_data);
			return (user_data);
		}
	}
	//TODO substr space
	user_data = delete_space(user_data);
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
		contacts[id].set_firstName(get_userdata("Enter first name     : "));
		contacts[id].set_lastName(get_userdata("Enter last name      : "));
		contacts[id].set_nickName(get_userdata("Enter nickname       : "));
		contacts[id].set_phoneNumber(get_userdata_num("Enter phone number   : "));
		contacts[id].set_darkestSecret(get_userdata("Enter darkest secret : "));		
	}
}

std::string right_length(std::string s)
{
	if (s.length() > MAX_LENGTH)
	{
		s = s.substr(0, 9);
		s += ".";
	}
	return (s);
}

int check_exist(int id, Contact contacts[8])
{

	if (contacts[id].get_firstName().empty())
		return (0);
	if (contacts[id].get_lastName().empty())
		return (0);
	if (contacts[id].get_nickName().empty())
		return (0);
	if (contacts[id].get_phoneNumber().empty())
		return (0);
	if (contacts[id].get_darkestSecret().empty())
		return (0);
	return (1);
}

int	display_contacts(Contact contacts[8])
{
	int i = 0;

	if (check_exist(i, contacts))
	{
		std::cout << "|     INDEX| FIRSTNAME|  LASTNAME|  NICKNAME|" << std::endl;
		std::cout << "|----------|----------|----------|----------|" << std::endl;
	}
	while (i < MAX_CONTACTS && check_exist(i, contacts))
	{
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << right_length(contacts[i].get_firstName());
		std::cout << "|" << std::setw(10) << right_length(contacts[i].get_lastName());
		std::cout << "|" << std::setw(10) << right_length(contacts[i].get_nickName()) << "|" << std::endl;
		i++;
	}
	if (i == 0)
	{
		std::cout << "You didn't have any contacts for the moment" << std::endl;
		return (0);
	}
	return (1);
}


void	PhoneBook::searchContact()
{
	std::string tmp;
	int id = -1;
	if (display_contacts(contacts))
	{
		while (tmp.empty() || !check_num(tmp))
		{
			std::cout << "Please select an index : " ;
			std::getline(std::cin, tmp);
			if (std::cin.fail() || std::cin.eof())
				return ;
			if (check_num(tmp) && !tmp.empty())
			{
				id = tmp[0] - '0';
				if (id < MAX_CONTACTS && check_exist(id, contacts))
				{
					std::cout << "First name     : " << contacts[id].get_firstName() << std::endl;
					std::cout << "Last name      : " << contacts[id].get_lastName() << std::endl;
					std::cout << "Nickname       : " << contacts[id].get_nickName() << std::endl;
					std::cout << "Phone number   : " << contacts[id].get_phoneNumber() << std::endl;
					std::cout << "Darkest secret : " << contacts[id].get_darkestSecret() << std::endl;
				}
				else
					std::cout << "Invalid index" << std::endl;
			}
		}
	}
}
