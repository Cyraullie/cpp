/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:40:08 by cgoldens          #+#    #+#             */
/*   Updated: 2025/11/12 15:52:20 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <stack>
#include <cctype>

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
	//std::stack st;
	std::string cmd = av[1];
	std::cout << ac << std::endl;
	std::cout << av[1] << std::endl;

	for (long unsigned int i = 0; i < cmd.length(); i++)
	{
		if (cmd[i] != ' ')
		{
			if (std::isdigit(cmd[i]))
				std::cout << cmd[i] << std::endl;
			else
				std::cout << cmd[i] << std::endl;

		}
	}
	return (0);
}