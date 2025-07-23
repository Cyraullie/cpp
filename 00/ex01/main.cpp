/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:36:37 by cgoldens          #+#    #+#             */
/*   Updated: 2025/07/23 14:40:00 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstdio>
#include <iostream>
#include <string>
#include <limits>
#include <cctype>
//TODO ADD
//TODO SEARCH

void displayCommand()
{
	std::cout << "Enter command ADD/SEARCH/EXIT: ";
}

bool handleInputError()
{
    if (!std::cin)
	{
        if (std::cin.eof())
		{
            std::cin.clear();
            std::cout << "\nCTRL+D was pressed. Exiting the program.\n";
            return true;
        } else
		{
            std::cin.clear();
            std::cout << "An error occurred while reading your input. Please try again.\n";
        }
    }
    return false;
}

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

//TODO delete space in start +end
//TODO convert multiple space to one
//TODO check if text are not empty or space

int	addContact(PhoneBook *phonebook)
{
	//TODO phoneNumber only numeric
	//TODO firstName & lastName no numeric
	if (std::cin.eof())
		return (-2);
	Contact	contact;
	std::string	firstName, lastName, nickname, phoneNumber, darkestSecret;
    
    firstName = get_userdata("Enter first name: ");
    lastName = get_userdata("Enter last name: ");
    nickname = get_userdata("Enter nickname: ");
    phoneNumber = get_userdata("Enter phone number: ");
    darkestSecret = get_userdata("Enter darkest secret: ");
  	std::cout << "" << firstName << " " << lastName << " " << nickname << " " << phoneNumber << " " << darkestSecret << "\n";
	phonebook->addContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
    return (0);
}

int searchContact(PhoneBook *phonebook)
{
    int id;
    std::string test;
	Contact	contact;
    (void)id;
    (void)phonebook;

    test = get_userdata("Enter phone number: ");
    std::cout << test;
    return 0;
}

int	main()
{
	PhoneBook	phonebook;
	std::string	command;

	while (true)
	{
		displayCommand();
        std::getline(std::cin, command);
		if (handleInputError()) {
            break;
        }
		if (command == "ADD")
			addContact(&phonebook);
		else if (command == "SEARCH")
			searchContact(&phonebook);
		else if (command == "EXIT")
			break;
	}
	return (0);
}