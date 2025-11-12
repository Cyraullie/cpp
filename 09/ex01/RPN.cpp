#include "RPN.hpp"

// Default constructor
RPN::RPN() : _name("")
{
	std::cout << GREEN << "Default RPN constructor called" << RESET << std::endl;
}

// Data constructor
RPN::RPN(std::string name) : _name(name)
{
	std::cout << LIGHT_GREEN << "RPN constructor called for " << ITALIC << name << RESET << std::endl;
}

// Copy constructor
RPN::RPN(const RPN& cpy) : _name(cpy._name)
{
	std::cout << LIGHT_GREEN << "RPN copy constructor called for " << ITALIC << cpy._name << RESET << std::endl;
}

// Destructor
RPN::~RPN()
{
	std::cout << RED << "RPN destructor called for " << ITALIC << this->_name << RESET << std::endl;
};

// Copy assignment
RPN& RPN::operator=(const RPN& src)
{
	std::cout << LIGHT_GREEN << "RPN assignment operator called" << RESET << std::endl;
	if (this != &src) {
		this->_name = src._name;
	}
	return *this;
}

// Example methods
void RPN::setName(const std::string& name) 
{
	this->_name = name;
}

const std::string& RPN::getName() const 
{
	return this->_name;
}
