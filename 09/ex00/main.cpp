/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:19:24 by cgoldens          #+#    #+#             */
/*   Updated: 2025/11/03 15:19:09 by cgoldens         ###   ########.fr       */
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

#include <cstdlib>


template<typename It>
void print_insertion_status(It it, bool success)
{
    std::cout << "Insertion of " << it->first
              << (success ? " succeeded\n" : " failed\n");
}

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


    std::map<std::string, float> data;
	
	std::ifstream db(CSV);
	std::ifstream cmd(av[1]);


	std::string name;
	std::string delimiter = ",";
	std::string date;
	std::string value;
	//float value;

	//TODO j'enregistre la date en string ou je la mets en time_t ?
    std::cout << db.good() << cmd.good() << std::endl;
	if (db.good() && cmd.good())
	{
		std::cout << "Hell yeah !" << std::endl;
	}
	//insert in map
	while (std::getline(db, name))
	{
		date = name.substr(0, name.find(delimiter));
		value = name.substr(name.find(delimiter) + 1, name.length());		
		data.insert(std::make_pair(date, std::atof(value.c_str())));
	}
	
	//read input to get data
	while (std::getline(cmd, name))
	{
		date = name.substr(0, name.find(" | "));
		value = name.substr(name.find(" | ") + 3, name.length());

		std::cout << name << std::endl;
		std::cout << date << " " << value << std::endl;
		
	
		
		std::cout << data[date] * std::atof(value.c_str()) << std::endl << std::endl;
		
   
		//std::cout << name << std::endl;
	}
	return (0);
}