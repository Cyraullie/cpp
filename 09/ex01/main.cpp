/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:40:08 by cgoldens          #+#    #+#             */
/*   Updated: 2026/03/05 11:01:06 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "missing argument ./RPN \"1 1 +\"" << std::endl;
		return (1);
	}

	RPN data;
	std::list<float> lst;
	std::string cmd = av[1];

	for (long unsigned int i = 0; i < cmd.length(); i++)
	{
		if (cmd[i] != ' ')
		{
			if (std::isdigit(cmd[i]))
			{
				if (std::atof(&cmd[i]) < 10)
					data.pushData(std::atof(&cmd[i]));
				else
				{
					std::cout << "Error: invalid number (0 - 9)" << std::endl;
					return (1);
				}
			}
			else
			{
				if (data.countListContent() == 2)
				{
					switch (cmd[i])
					{
						case '+':
							data.addition();
							break;
						case '-':
							data.substraction();
							break;
						case '*':
							data.multiple();

							break;
						case '/':
							data.division();

							break;
						default:
							std::cout << "Error: Invalid element '" << cmd[i] << "'" << std::endl;
							return (1);
							break;
					}
				}
				else
				{
					std::cout << "Error: Not enough number in calculation" << std::endl;
					return (1);
				}
			}

		}
	}
	if (data.countListContent() == 1)
		data.listData();
	else
	{
		std::cout << "Error: Too many element in final result" << std::endl;
		return (1);
	}
	return (0);
}