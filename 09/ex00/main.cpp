/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:19:24 by cgoldens          #+#    #+#             */
/*   Updated: 2025/11/04 15:34:53 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <time.h>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <ctime>
#include <iterator>
#include <locale>
#include <cassert>
#include <cstring>
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
	BitcoinExchange *bc = new BitcoinExchange();

    std::map<std::string, float> data;
	
	std::ifstream cmd(av[1]);

	std::string name;

	//float value;

	//TODO j'enregistre la date en string ou je la mets en time_t ?
    std::cout << cmd.good() << std::endl;
	if (cmd.good())
	{
			//read input to get data
		while (std::getline(cmd, name))
		{
			try
			{
				bc->getDbInput(name);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
			
	
			//std::cout << name << std::endl;
		}
	}
	

	return (0);
}