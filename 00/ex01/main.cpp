/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:36:37 by cgoldens          #+#    #+#             */
/*   Updated: 2025/07/22 13:39:19 by cgoldens         ###   ########.fr       */
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

//TODO delete space in start +end
//TODO convert multiple space to one
//TODO check if text are not empty or space

int	addContact(PhoneBook& phonebook)
{
	//TODO phoneNumber only numeric
	//TODO firstName & lastName no numeric
	(void)phonebook;
	if (std::cin.eof())
		return (-2);
	Contact	contact;
	std::string	firstName, lastName, nickname, phoneNumber, darkestSecret;

	std::cout << "Enter first name: ";
    std::getline(std::cin, firstName);
    if (std::cin.eof())
    {
        std::cout << "\nCTRL+D was pressed. Exiting addContact.\n";
        return (-2);
    }
	std::cout << "Enter last name: ";
    std::getline(std::cin, lastName);
	if (std::cin.eof())
    {
        std::cout << "\nCTRL+D was pressed. Exiting addContact.\n";
        return (-2);
    }
	std::cout << "Enter nickname: ";
    std::getline(std::cin, nickname);
	if (std::cin.eof())
    {
        std::cout << "\nCTRL+D was pressed. Exiting addContact.\n";
        return (-2);
    }
	std::cout << "Enter phone number: ";
    std::getline(std::cin, phoneNumber);
	if (std::cin.eof())
    {
        std::cout << "\nCTRL+D was pressed. Exiting addContact.\n";
        return (-2);
    }
	std::cout << "Enter darkest secret: ";
    std::getline(std::cin, darkestSecret);
	if (std::cin.eof())
    {
        std::cout << "\nCTRL+D was pressed. Exiting addContact.\n";
        return (-2);
    }
  	std::cout << "" << firstName << " " << lastName << " " << nickname << " " << phoneNumber << " " << darkestSecret << "\n";
	return (0);
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
			addContact(phonebook);
		else if (command == "SEARCH")
			printf("SEARCH\n");
		else if (command == "EXIT")
			break;
	}
	return (0);
}