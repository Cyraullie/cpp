#include "Intern.hpp"

// Default constructor
Intern::Intern() : _name("")
{
	std::cout << GREEN << "Default Intern constructor called" << RESET << std::endl;
}

// Data constructor
Intern::Intern(std::string name) : _name(name)
{
	std::cout << LIGHT_GREEN << "Intern constructor called for " << ITALIC << name << RESET << std::endl;
}

// Copy constructor
Intern::Intern(const Intern& cpy) : _name(cpy._name)
{
	std::cout << LIGHT_GREEN << "Intern copy constructor called for " << ITALIC << cpy._name << RESET << std::endl;
}

// Copy assignment
Intern& Intern::operator=(const Intern& src)
{
	std::cout << LIGHT_GREEN << "Intern assignment operator called" << RESET << std::endl;
	if (this != &src) {
		this->_name = src._name;
	}
	return *this;
}

// Destructor
Intern::~Intern()
{
	std::cout << RED << "Intern destructor called for " << ITALIC << this->_name << RESET << std::endl;
};

// Example methods
void Intern::setName(const std::string& name) 
{
	this->_name = name;
}

const std::string& Intern::getName() const 
{
	return this->_name;
}
