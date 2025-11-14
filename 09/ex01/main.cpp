/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:40:08 by cgoldens          #+#    #+#             */
/*   Updated: 2025/11/14 11:27:52 by cgoldens         ###   ########.fr       */
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

int main(int ac, char **av)
{
	RPN data;
	std::list<float> lst;
	std::string cmd = av[1];
	std::cout << ac << std::endl;
	std::cout << av[1] << std::endl;

	for (long unsigned int i = 0; i < cmd.length(); i++)
	{
		if (cmd[i] != ' ')
		{
			if (std::isdigit(cmd[i]))
			{
				std::cout << cmd[i] << std::endl;
				data.pushData(std::atof(&cmd[i]));
			}
			else
			{
				std::cout << cmd[i] << std::endl;
				switch (cmd[i])
				{
					case '+':
						std::cout << "+++++++" << std::endl;
						data.addition();
						break;
					case '-':
						std::cout << "-------" << std::endl;
						data.substraction();

						break;
					case '*':
						std::cout << "*******" << std::endl;
						data.multiple();

						break;
					case '/':
						std::cout << "///////" << std::endl;
						data.division();

						break;
					default:
						std::cout << "Error" << std::endl;
						return (1);
						break;
				}

				data.listData();
			}

		}
	}

	// std::list<float>::iterator it;
	// for (it = lst.begin(); it != lst.end(); ++it){
	// 	std::cout << it->;
	// }
	// Source - https://stackoverflow.com/a
// Posted by Simple
// Retrieved 2025-11-14, License - CC BY-SA 3.0

	data.listData();

	return (0);
}