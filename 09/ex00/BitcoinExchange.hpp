/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:19:27 by cgoldens          #+#    #+#             */
/*   Updated: 2025/11/04 15:42:28 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <iostream>
# include <fstream>
# include <ctime>
# include "colors.hpp"
# include <map>
# include <cstdlib>

# define CSV "./data.csv"

class BitcoinExchange
{
	private:
		std::map<std::string, float> _db;

	public:
		// *** CANONICAL METHODS***
		BitcoinExchange();										// Default constructor
		//BitcoinExchange(std::string name);						// Data constructor
		BitcoinExchange(const BitcoinExchange& cpy);				// Copy constructor
		~BitcoinExchange();									// Destructor

		BitcoinExchange& operator=(const BitcoinExchange& src);	// Copy assignment

		// *** SET METHODS***

		// *** GET METHODS***
		void getDbInput(std::string cmd);

		// *** OTHER METHODS***

		class notPositiveException : public std::exception
		{
			public:
				virtual const char *what() const throw(){return ("Error: not a positive number");};
		};
		
};

#endif // BITCOINEXCHANGE_HPP
