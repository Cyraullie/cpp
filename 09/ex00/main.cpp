/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:19:24 by cgoldens          #+#    #+#             */
/*   Updated: 2025/11/12 15:28:07 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << RED << "Error: could not open file." << RESET << std::endl; 
		return (1);
	}
	else if (ac > 2)
	{
		std::cout << RED << "Error: too much arguments !" << RESET << std::endl; 
		return (1);
	}
	
	BitcoinExchange *bc = new BitcoinExchange();
    std::map<std::string, float> data;
	std::ifstream cmd(av[1]);
	std::string name;

	if (cmd.good())
	{
		while (std::getline(cmd, name))
		{
			if (name.find("date"))
			{
				try
				{
					bc->getDbInput(name);
				}
				catch(const std::exception& e)
				{
					std::cerr << e.what() << '\n';
				}
			}
		}
	}
	return (0);
}