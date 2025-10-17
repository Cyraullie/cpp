#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include "colors.hpp"
# include <stdlib.h>
# include <sstream>

class ScalarConverter
{
	private:
		ScalarConverter();										// Default constructor
		ScalarConverter(const ScalarConverter& cpy);				// Copy constructor
		~ScalarConverter();									// Destructor

		ScalarConverter& operator=(const ScalarConverter& src);	// Copy assignment
		static void convertDouble();
		static void convertFloat();
		static void convertInt();
		static void convertChar();

	public:
		static void convert(std::string const &str);

};

#endif // SCALARCONVERTER_HPP
