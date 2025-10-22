/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:36:29 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/22 15:36:30 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <iostream>
# include "colors.hpp"
# include <stdlib.h>
# include <sstream>
# include <cctype>
# include <iomanip>
# include <cmath>

class ScalarConverter
{
	private:
		ScalarConverter();										// Default constructor
		ScalarConverter(const ScalarConverter& cpy);				// Copy constructor
		~ScalarConverter();									// Destructor

		ScalarConverter& operator=(const ScalarConverter& src);	// Copy assignment
		static void convertChar(char c);
		static void convertInt(int nbr);
		static void convertFloat(float nbr);
		static void convertDouble(double nbr);

		static bool checkDigit(std::string s);
		static bool checkDouble(std::string s);
		static bool checkFloat(std::string s);

	public:
		static void convert(std::string const &str);

};

#endif // SCALARCONVERTER_HPP
