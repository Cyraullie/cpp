/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 11:43:08 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/07 11:43:09 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

// Default constructor
Form::Form() : _name("")
{
	std::cout << GREEN << "Default Form constructor called" << RESET << std::endl;
}

// Data constructor
Form::Form(std::string name) : _name(name)
{
	std::cout << LIGHT_GREEN << "Form constructor called for " << ITALIC << name << RESET << std::endl;
}

// Copy constructor
Form::Form(const Form& cpy) : _name(cpy._name)
{
	std::cout << LIGHT_GREEN << "Form copy constructor called for " << ITALIC << cpy._name << RESET << std::endl;
}

// Copy assignment
Form& Form::operator=(const Form& src)
{
	if (this != &src) {
		this->_name = src._name;
	}
	return *this;
}

// Destructor
Form::~Form()
{
	std::cout << RED << "Form destructor called for " << ITALIC << this->_name << RESET << std::endl;
};

// Example methods
void Form::setName(const std::string& name) 
{
	this->_name = name;
}

const std::string& Form::getName() const 
{
	return this->_name;
}
