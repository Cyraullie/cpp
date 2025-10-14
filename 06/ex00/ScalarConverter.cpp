#include "ScalarConverter.hpp"

// Default constructor
ScalarConverter::ScalarConverter() : _name("")
{
	std::cout << GREEN << "Default ScalarConverter constructor called" << RESET << std::endl;
}

// Data constructor
ScalarConverter::ScalarConverter(std::string name) : _name(name)
{
	std::cout << LIGHT_GREEN << "ScalarConverter constructor called for " << ITALIC << name << RESET << std::endl;
}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter& cpy) : _name(cpy._name)
{
	std::cout << LIGHT_GREEN << "ScalarConverter copy constructor called for " << ITALIC << cpy._name << RESET << std::endl;
}

// Destructor
ScalarConverter::~ScalarConverter()
{
	std::cout << RED << "ScalarConverter destructor called for " << ITALIC << this->_name << RESET << std::endl;
};

// Copy assignment
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src)
{
	std::cout << LIGHT_GREEN << "ScalarConverter assignment operator called" << RESET << std::endl;
	if (this != &src) {
		this->_name = src._name;
	}
	return *this;
}

// Example methods
void ScalarConverter::setName(const std::string& name) 
{
	this->_name = name;
}

const std::string& ScalarConverter::getName() const 
{
	return this->_name;
}
