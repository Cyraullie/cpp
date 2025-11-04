/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:19:30 by cgoldens          #+#    #+#             */
/*   Updated: 2025/11/04 15:42:17 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Default constructor
BitcoinExchange::BitcoinExchange()
{
	std::cout << GREEN << "Default BitcoinExchange constructor called" << RESET << std::endl;
	
	std::ifstream db(CSV);
	std::string name;
	std::string delimiter = ",";
	std::string date;
	std::string value;

	if (db.good())
	{
		//insert in map
		while (std::getline(db, name))
		{
			date = name.substr(0, name.find(delimiter));
			value = name.substr(name.find(delimiter) + 1, name.length());		
			this->_db.insert(std::make_pair(date, std::atof(value.c_str())));
		}
	}	
}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange& cpy)
{
	(void)cpy;
	std::cout << LIGHT_GREEN << "BitcoinExchange copy constructor called " << RESET << std::endl;
}

// Destructor
BitcoinExchange::~BitcoinExchange()
{
	std::cout << RED << "BitcoinExchange destructor called " << RESET << std::endl;
};

// Copy assignment
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
	std::cout << LIGHT_GREEN << "BitcoinExchange assignment operator called" << RESET << std::endl;
	if (this != &src) {
		//this->_name = src._name;
	}
	return *this;
}

void BitcoinExchange::getDbInput(std::string cmd)
{
	float res;
	std::string delimiter = " | ";
	std::string date;
	std::string value;

	date = cmd.substr(0, cmd.find(delimiter));
	value = cmd.substr(cmd.find(delimiter) + delimiter.length(), cmd.length());

	//std::cout << cmd << std::endl;
	//std::cout << date << " " << value << std::endl;
	
	//TODO check date valid
	//TODO check res is valid (not too large or too small)
	//TODO if date dont exist in map find le plus proche

	//std::cout << this->_db[date] * std::atof(value.c_str()) << std::endl << std::endl;
	res = this->_db[date] * std::atof(value.c_str());
	if (res < 0)
		throw(BitcoinExchange::notPositiveException());
	
	std::cout << date << " => " << value << " = " << res << std::endl;
}
