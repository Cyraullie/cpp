/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:19:24 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/31 15:51:18 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <time.h>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <ctime>
#include <iostream>
#include <iterator>
#include <locale>
#include <cassert>
#include <cstring>
#include <iostream>
#include <vector>

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << RED << "Error: could not open file." << RESET << std::endl; 
		return (1);
	}
	else if (ac > 2)
	{
		std::cout << RED << "Error: too much arguments !" << RESET << std::endl; 
		return (1);
	}
	
	std::cout << ac << " " << av[1] << std::endl;

	std::string d = "2009-01-20";
	std::string f = "";

	std::time_t t = time(0);
    char timeString[std::size_t("2009-01-20")];
    std::strftime(timeString, std::size_t(timeString),
                  "%Y-%m-%d", std::gmtime(&t));
    std::cout << timeString << '\n';

	std::ifstream db(CSV);
	std::ifstream cmd(av[1]);
	//TODO j'enregistre la date en string ou je la mets en time_t ?
    std::cout << db.good() << cmd.good() << std::endl;
	if (db.good() && cmd.good())
	{
		std::cout << "Hell yeah !" << std::endl;
	}
	return (0);
}