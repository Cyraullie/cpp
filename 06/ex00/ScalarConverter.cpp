#include "ScalarConverter.hpp"

// Default constructor
ScalarConverter::ScalarConverter()
{
	std::cout << GREEN << "Default ScalarConverter constructor called" << RESET << std::endl;
}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter& cpy)
{
	(void)cpy;
	std::cout << LIGHT_GREEN << "ScalarConverter copy constructor called for " << RESET << std::endl;
}

// Destructor
ScalarConverter::~ScalarConverter()
{
	std::cout << RED << "ScalarConverter destructor called for " << ITALIC << RESET << std::endl;
};

// Copy assignment
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& src)
{
	std::cout << LIGHT_GREEN << "ScalarConverter assignment operator called" << RESET << std::endl;
	(void)src;
	return *this;
}

void ScalarConverter::convertDouble(std::string const &str)
{

}

void ScalarConverter::convertFloat(std::string const &str)
{
	//TODO if .0 add it 
	//TODO add f at the end
}

void ScalarConverter::convertInt(std::string const &str)
{

}

void ScalarConverter::convertChar(std::string const &str)
{

}

void ScalarConverter::convert(std::string const &str)
{

	std::cout << "default : " << str << std::endl;

	int i;
	// float f;
	// double d;
	//TODO fonctionne uniquement avec les chiffres ?
    std::stringstream strm(str);

	// string -> integer
	strm >> i;

	// string -> float
	// std::istringstream ( str ) >> f;

	// // string -> double 
	// std::istringstream ( str ) >> d;

	std::cout << "string to int : " << i << std::endl;
	std::cout << "string to float : " << std::atof(str.c_str()) << "f" << std::endl;
}
