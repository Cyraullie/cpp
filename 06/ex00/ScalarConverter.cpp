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

void ScalarConverter::convertDouble(double nbr)
{
	if (nbr < 128 && nbr >= 0)
	{
		if (std::isprint(nbr))
			std::cout << CYAN << "char: '" << static_cast<char>(nbr) << "'" << RESET << std::endl;
		else
			std::cout << CYAN << "char: Non displayable" << RESET << std::endl;
	}
	else
		std::cout << CYAN << "char: impossible" << RESET << std::endl;
	std::cout << GREEN << "int: " << static_cast<int>(nbr) << RESET << std::endl;
	std::cout << YELLOW << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(nbr) << "f" << RESET << std::endl;
	std::cout << MAGENTA << std::fixed << std::setprecision(1) << "double: " << nbr << RESET << std::endl;

}

void ScalarConverter::convertFloat(float nbr)
{
	std::cout << nbr << std::endl;
	if (nbr < 128 && nbr >= 0)
	{
		if (std::isprint(nbr))
			std::cout << CYAN << "char: '" << static_cast<char>(nbr) << "'" << RESET << std::endl;
		else
			std::cout << CYAN << "char: Non displayable" << RESET << std::endl;
	}
	else
		std::cout << CYAN << "char: impossible" << RESET << std::endl;
	std::cout << GREEN << "int: " << static_cast<int>(nbr) << RESET << std::endl;
	std::cout << YELLOW << std::fixed << std::setprecision(1) << "float: " << nbr << "f" << RESET << std::endl;
	std::cout << MAGENTA << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(nbr) << RESET << std::endl;

}

void ScalarConverter::convertInt(int nbr)
{
	if (nbr < 128 && nbr >= 0)
	{
		if (std::isprint(nbr))
			std::cout << CYAN << "char: '" << static_cast<char>(nbr) << "'" << RESET << std::endl;
		else
			std::cout << CYAN << "char: Non displayable" << RESET << std::endl;
	}
	else
		std::cout << CYAN << "char: impossible" << RESET << std::endl;
	std::cout << GREEN << "int: " << nbr << RESET << std::endl;
	std::cout << YELLOW << std::fixed << std::setprecision(1) << "float: " << static_cast<float>(nbr) << "f" << RESET << std::endl;
	std::cout << MAGENTA << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(nbr) << RESET << std::endl;
}

void ScalarConverter::convertChar(char c)
{
	std::cout << CYAN << "char: '" << c << "'" << RESET << std::endl;
	std::cout << GREEN << "int: " << static_cast<int>(c) << RESET << std::endl;
	std::cout << YELLOW << "float: "  << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << RESET << std::endl;
	std::cout << MAGENTA << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << RESET << std::endl;
}

bool ScalarConverter::checkDigit(std::string s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if (!std::isdigit(s[i]))
			return (0);
	}
	return (1);
}

bool ScalarConverter::checkDouble(std::string s)
{
	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] == '.')
			i++;
		if (!std::isdigit(s[i]))
			return (0);
	}
	return (1);
}

bool ScalarConverter::checkFloat(std::string s)
{
	size_t size = s.length();

	for (size_t i = 0; i < s.length(); i++)
	{
		if (s[i] == '.')
			i++;
		if(s[i] == 'f')
		{
			i++;
			if (i == size)
				return 1;
		}
		if (!std::isdigit(s[i]))
			return (0);
	}
	return (1);
}

void ScalarConverter::convert(std::string const &str)
{
	if ((str == "nan" || str == "+inf" || str == "-inf"))
	{
		std::cout << CYAN << "char: impossible" << RESET << std::endl;
		std::cout << GREEN << "int: impossible" << RESET << std::endl;
		std::cout << YELLOW << "float: " << str << "f" << RESET << std::endl;
		std::cout << MAGENTA << "double: " << str << RESET << std::endl;
		return ;
	}
	else if ((str == "nanf" || str == "+inff" || str == "-inff"))
	{
		std::cout << CYAN << "char: impossible" << RESET << std::endl;
		std::cout << GREEN << "int: impossible" << RESET << std::endl;
		std::cout << YELLOW << "float: " << str << RESET << std::endl;
		std::cout << MAGENTA << "double: " << str.substr(0, str.length() - 1) << RESET << std::endl;
		return ;
	}

	if (str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]))
	{
		convertChar(str.c_str()[0]);
		return ;
	}
	else if (!(str.find('.') != std::string::npos) && checkDigit(str))
	{
		int nbr = std::atoi(str.c_str());
		convertInt(nbr);
		return ;
	}
	else if ((str.find('.') != std::string::npos) && (str.find('f') != std::string::npos) && checkFloat(str))
	{
		float f = std::atof(str.c_str());
		convertFloat(f);
		return ;
	}
	else if ((str.find('.') != std::string::npos) && checkDouble(str))
	{
		double d = std::atof(str.c_str());
		convertDouble(d);
		return ;
	}
	else
		std::cout << RED << "Not a right type !" << RESET << std::endl;
}
