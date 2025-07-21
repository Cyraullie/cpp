/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:36:37 by cgoldens          #+#    #+#             */
/*   Updated: 2025/07/21 15:10:36 by cgoldens         ###   ########.fr       */
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

int	addContact(PhoneBook& phonebook)
{
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
		//TODO display information
        std::getline(std::cin, command);
		if (command == "ADD")
			addContact(phonebook);
		else if (command == "SEARCH")
			printf("SEARCH\n");
		else if (command == "EXIT")
			break;
	}
	return (0);
}