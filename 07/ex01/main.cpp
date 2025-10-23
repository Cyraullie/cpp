/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:51:07 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/23 13:34:59 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include "colors.hpp"

int main(void)
{
	int tab[5] = {0, 1, 2, 3, 4};

	std::cout << YELLOW << BOLD << "*** TRY WITH A TAB OF INT ***" << RESET << std::endl;
	std::cout << "print: " << std::endl;
	::iter(tab, 5, ::print);
	std::cout << "increment & reprint: " << std::endl;
	::iter(tab, 5, ::increment);
	::iter(tab, 5, ::print);

	char chars[11] = "testouille";

	std::cout << YELLOW << BOLD << "*** TRY WITH A TAB OF CHAR ***" << RESET << std::endl;
	std::cout << "print: " << std::endl;
	::iter(chars, 11, ::print);
	std::cout << "increment & reprint: " << std::endl;
	::iter(chars, 11, ::increment);
	::iter(chars, 11, ::print);

	double doubles[6] = {2.5, 1.2, 4.2, 5.5, 7.0, 6.9};

	std::cout << YELLOW << BOLD << "*** TRY WITH A TAB OF DOUBLE ***" << RESET << std::endl;
	std::cout << "print: " << std::endl;
	::iter(doubles, 6, ::print);
	std::cout << "increment & reprint: " << std::endl;
	::iter(doubles, 6, ::increment);
	::iter(doubles, 6, ::print);

	const int ctab[3] = {4, 2, 0};
	
	std::cout << YELLOW << BOLD << "*** TRY WITH A CONST TAB OF INT ***" << RESET << std::endl;
	std::cout << "print: " << std::endl;
	::iter(ctab, 3, ::print);
	std::cout << "obviously we can't do increment" << std::endl;

	std::string strings[3] = {"hello", "World", "42"};
	
	std::cout << YELLOW << BOLD << "*** TRY WITH A TAB OF STRINGS ***" << RESET << std::endl;
	::iter(strings, 3, ::print);
	std::cout << "we can't increment a string" << std::endl;
}