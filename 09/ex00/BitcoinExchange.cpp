/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:19:30 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/31 15:19:30 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Default constructor
BitcoinExchange::BitcoinExchange() : _name("")
{
	std::cout << GREEN << "Default BitcoinExchange constructor called" << RESET << std::endl;
}

// Data constructor
BitcoinExchange::BitcoinExchange(std::string name) : _name(name)
{
	std::cout << LIGHT_GREEN << "BitcoinExchange constructor called for " << ITALIC << name << RESET << std::endl;
}

// Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange& cpy) : _name(cpy._name)
{
	std::cout << LIGHT_GREEN << "BitcoinExchange copy constructor called for " << ITALIC << cpy._name << RESET << std::endl;
}

// Destructor
BitcoinExchange::~BitcoinExchange()
{
	std::cout << RED << "BitcoinExchange destructor called for " << ITALIC << this->_name << RESET << std::endl;
};

// Copy assignment
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
	std::cout << LIGHT_GREEN << "BitcoinExchange assignment operator called" << RESET << std::endl;
	if (this != &src) {
		this->_name = src._name;
	}
	return *this;
}

// Example methods
void BitcoinExchange::setName(const std::string& name) 
{
	this->_name = name;
}

const std::string& BitcoinExchange::getName() const 
{
	return this->_name;
}
