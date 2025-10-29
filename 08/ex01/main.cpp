/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:45:32 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/29 15:48:51 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(void)
{
	Span span(6);
	Span empty;
	Span ranger(10000);
	try
	{
		std::cout << BOLD << "----- TOO MUCH NUMBER -----" << RESET << std::endl;
		span.addNumber(3);
		span.addNumber(6);
		span.addNumber(42);
		span.addNumber(-4);
		span.addNumber(666);
		span.addNumber(43);
		span.addNumber(-2);
		span.addNumber(56);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	span.printMultiset();
	try
	{
		std::cout << "longest span: " << span.longestSpan() << std::endl;
		std::cout << "shortest span: " << span.shortestSpan() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr  << e.what() << std::endl;
	}
	// std::cout << BOLD << "----- TRY TO DO OPERATION ON EMPTY SPAN -----" << RESET << std::endl;
	// try
	// {
	// 	std::cout << "*** try to add number ***" << std::endl;
	// 	empty.addNumber(96);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// try
	// {
	// 	std::cout << "*** try to do longest span ***" << std::endl;
	// 	empty.longestSpan();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << BOLD << "----- TRY ASSIGNMENT OPERATOR OVERLOAD -----" << RESET << std::endl;
	// try
	// {
	// 	std::cout << "*** try empty = span ***" << std::endl;
	// 	std::cout << "empty before: ";
	// 	empty.printMultiset();
	// 	std::cout << "span before: ";
	// 	span.printMultiset();
	// 	empty = span;
	// 	std::cout << "empty after: ";
	// 	empty.printMultiset();
	// 	std::cout << "span after: ";
	// 	span.printMultiset();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;;
	// }

	// std::cout << BOLD << "----- TRY TO ADD A RANGE OF NUMBERS -----" << RESET << std::endl;

	// try
	// {
	// 	std::vector<int> v;
	// 	std::vector<int> v2;

	// 	for (size_t i = 0; i < 10000; i++)
	// 		v.push_back(i + 1);

	// 	std::cout << "*** try to add 1000 number in range of 0 to 10000 ***" << std::endl;
	// 	ranger.addNumbers(v.begin(), v.end());
	// 	ranger.printMultiset();

	// 	std::cout << "*** try to add too much number with a range ***" << std::endl;
	// 	for (size_t i = 0; i < 12000; i++)
	// 		v2.push_back(i);
	// 	ranger.addNumbers(v2.begin(), v2.end());

	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << RED << e.what() << RESET << std::endl;
	// }
}