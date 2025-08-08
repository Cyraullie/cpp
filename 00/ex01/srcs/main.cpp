/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:36:37 by cgoldens          #+#    #+#             */
/*   Updated: 2025/08/08 14:42:03 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <cstdio>
#include <iostream>
#include <string>
#include <limits>
#include <cctype>

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

int	main()
{
	int			id = 0;
	PhoneBook	phonebook;
	std::string	command;

	while (true)
	{
		if (id == MAX_CONTACTS)
		{
			id = 0;
		}
		displayCommand();
        std::getline(std::cin, command);
		if (handleInputError()) {
            break;
        }
		if (command == "ADD")
		{
			phonebook.addContact(id);
			id++;
		}
		else if (command == "SEARCH")
			phonebook.searchContact();
		else if (command == "EXIT")
			break;
	}
	return (0);
}