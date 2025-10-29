/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:45:38 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/29 14:51:22 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <string>
# include <iostream>
# include <set>
# include <algorithm>
# include "colors.hpp"

class Span
{
	private:
		unsigned int _N;
		std::multiset<int>	_multiset;

	public:
		// *** CANONICAL METHODS***
		Span();										// Default constructor
		Span(unsigned int n);						// Data constructor
		Span(const Span& cpy);				// Copy constructor
		~Span();									// Destructor

		Span& operator=(const Span& src);	// Copy assignment

		// *** SET METHODS***
		void	addNumber(int n);
		
		// *** GET METHODS***
		unsigned int shortestSpan();
		unsigned int longestSpan();
		
		// *** OTHER METHODS***
		void	printMultiset() const;

};

#endif // SPAN_HPP
