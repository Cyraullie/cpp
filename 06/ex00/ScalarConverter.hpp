#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include "colors.hpp"

class ScalarConverter
{
	private:
		std::string _name;

	public:
		ScalarConverter();										// Default constructor
		ScalarConverter(std::string name);						// Data constructor
		ScalarConverter(const ScalarConverter& cpy);				// Copy constructor
		~ScalarConverter();									// Destructor

		ScalarConverter& operator=(const ScalarConverter& src);	// Copy assignment

		// --- Example methods ---
		static void convert(std::string const &str);
		void setName(const std::string& name);
		const std::string& getName() const;

};

#endif // SCALARCONVERTER_HPP
