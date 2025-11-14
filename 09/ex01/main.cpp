/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:40:08 by cgoldens          #+#    #+#             */
/*   Updated: 2025/11/14 15:29:36 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
//https://medium.com/@interviewbuddies/reverse-polish-notation-b88524252960

//7 7 * 7 -
//7 - 7 * 7

//TODO container = stack
//TODO push number 
//TODO operand do and pop
//7 7 * 7 -
// push 7 push 7
// multiple stack = 49
// pop 7 pop 7
//push 7
// submiss stack (49 - 7) = 42
// result 42

//1 2 * 2 / 2 * 2 4 - +
//1*2 2
//2/2 1
//1*2 2
//2-4 -2
//2+2

int main(int ac, char **av)
{
	RPN data;
	std::list<float> lst;
	std::string cmd = av[1];

	if (ac != 2)
	{
		std::cout << "missing argument ./RPN \"1 1 +\"" << std::endl;
		return (1);
	}

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