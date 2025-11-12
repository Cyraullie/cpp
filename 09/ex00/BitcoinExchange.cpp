/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:19:30 by cgoldens          #+#    #+#             */
/*   Updated: 2025/11/12 15:32:03 by cgoldens         ###   ########.fr       */
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

bool isLeapYear(int year) {
    // Année bissextile : divisible par 4 mais pas par 100, sauf si divisible par 400
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    return (year % 4 == 0);
}

bool BitcoinExchange::checkDate(std::string date)
{
	if (date.length() != 10)
		return false;

	if (date[4] != '-' || date[7] != '-')
		return false;
		
	std::string y;
	std::string m;
	std::string d;
	std::string delimiter = "-";

	y = date.substr(0, date.find(delimiter));
	date.erase(0, date.find(delimiter) + delimiter.length());

	m = date.substr(0, date.find(delimiter));
	date.erase(0, date.find(delimiter) + delimiter.length());

	d = date.substr(0, date.length());

	int year = atoi(y.c_str());
    int month = atoi(m.c_str());
    int day = atoi(d.c_str());

    if (month < 1 || month > 12)
        return false;

    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Ajustement pour année bissextile
    if (isLeapYear(year))
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;
}

void BitcoinExchange::getDbInput(std::string cmd)
{
	float res;
	std::string delimiter = " | ";
	std::string date;
	std::string value;

	date = cmd.substr(0, cmd.find(delimiter));
	value = cmd.substr(cmd.find(delimiter) + delimiter.length(), cmd.length());
	
	if (!this->checkDate(date))
		throw (BitcoinExchange::badInputException(date));
	res = this->_db.lower_bound(date)->second * std::atof(value.c_str());
	if (res < 0)
		throw (BitcoinExchange::notPositiveException());
	if (std::atol(value.c_str()) > 1000)
		throw (BitcoinExchange::tooLargeException());
	std::cout << date << " => " << value << " = " << res << std::endl;
}
