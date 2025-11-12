/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:19:27 by cgoldens          #+#    #+#             */
/*   Updated: 2025/11/12 14:45:15 by cgoldens         ###   ########.fr       */
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
		bool checkDate(std::string date);

		class notPositiveException : public std::exception
		{
			public:
				virtual const char *what() const throw(){return ("Error: not a positive number");};
		};
		class badInputException : public std::exception
		{
		private:
			std::string _date;
			std::string _message;

		public:
			// Constructeur qui reçoit la date
			badInputException(const std::string &date)
				: _date(date)
			{
				_message = "Error: bad input => " + _date;
			}

			// Destructeur virtuel requis par la norme C++98
			virtual ~badInputException() throw() {}

			// Méthode what() qui retourne le message complet
			virtual const char *what() const throw()
			{
				return _message.c_str();
			}
		};
		
};

#endif // BITCOINEXCHANGE_HPP
