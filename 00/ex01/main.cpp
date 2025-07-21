/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 10:36:37 by cgoldens          #+#    #+#             */
/*   Updated: 2025/07/21 12:35:24 by cgoldens         ###   ########.fr       */
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
//TODO EXIT

int	main()
{
	std::string command;

	while (true)
	{
        std::getline(std::cin, command);
		if (command == "ADD")
			printf("ADD\n");
		if (command == "SEARCH")
			printf("SEARCH\n");
		if (command == "EXIT")
			break;
	}
}