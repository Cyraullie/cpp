/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 11:16:30 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/02 13:00:10 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

void	Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout << " cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;

	for (i = 0; i <= 4; i++)
	{
		if (level == levels[i])
		{
			break ;
		}
	}
	
	switch (i)
	{
		case 0:
			std::cout << "[ " << levels[0] << " ]" << std::endl;
			this->debug();
			std::cout << std::endl;
    		// fallthrough
		case 1:
			std::cout << "[ " << levels[1] << " ]" << std::endl;
			this->info();
			std::cout << std::endl;
    		// fallthrough
		case 2:
			std::cout << "[ " << levels[2] << " ]" << std::endl;
			this->warning();
			std::cout << std::endl;
    		// fallthrough
		case 3:
			std::cout << "[ " << levels[3] << " ]" << std::endl;
			this->error();
			std::cout << std::endl;
			break;
		default:
			std::cerr << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
}
