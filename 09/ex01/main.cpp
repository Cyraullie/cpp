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