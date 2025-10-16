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
		static void convertDouble(std::string const &str);
		static void convertFloat(std::string const &str);
		static void convertInt(std::string const &str);
		static void convertChar(std::string const &str);

	public:
		static void convert(std::string const &str);

};

#endif // SCALARCONVERTER_HPP
