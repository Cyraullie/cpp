/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:19:27 by cgoldens          #+#    #+#             */
/*   Updated: 2025/11/03 15:19:55 by cgoldens         ###   ########.fr       */
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

# define CSV "./data.csv"

class BitcoinExchange
{
	private:
		std::string _name;
		std::map<std::string, float> _db;

	public:
		// *** CANONICAL METHODS***
		BitcoinExchange();										// Default constructor
		BitcoinExchange(std::string name);						// Data constructor
		BitcoinExchange(const BitcoinExchange& cpy);				// Copy constructor
		~BitcoinExchange();									// Destructor

		BitcoinExchange& operator=(const BitcoinExchange& src);	// Copy assignment

		// *** SET METHODS***
		void setName(const std::string& name);

		// *** GET METHODS***
		const std::string& getName() const;

		// *** OTHER METHODS***

};

#endif // BITCOINEXCHANGE_HPP
