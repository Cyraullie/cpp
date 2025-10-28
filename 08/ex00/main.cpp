/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 14:10:47 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/28 15:44:53 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.tpp"

int main(void)
{
	std::cout << YELLOW << BOLD << "----------------TEST VECTOR----------------" << RESET << std::endl;
  	std::vector<int> vect;
	vect.push_back(0);
	vect.push_back(1);
	vect.push_back(2);
	vect.push_back(3);
	vect.push_back(4);
	std::cout << LIGHT_BLUE << "Print container content" << RESET << std::endl;
	::printContainer(vect);
	try
	{
		std::cout << LIGHT_BLUE << "try to find 5" << RESET << std::endl;
		std::cout << GREEN << "Result: " << *easyfind(vect, 5) << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	try
	{
		std::cout << LIGHT_BLUE << "try to find 1" << RESET << std::endl;
		std::cout << GREEN << "Result: " << *easyfind(vect, 1) << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}

	std::cout << YELLOW << BOLD << "----------------TEST DEQUE----------------" << RESET << std::endl;
	std::deque<int> deq;
	deq.push_back(0);
	deq.push_back(1);
	deq.push_back(2);
	deq.push_back(3);
	deq.push_back(4);
	deq.push_back(5);
	std::cout << LIGHT_BLUE << "Print container content" << RESET << std::endl;
	::printContainer(deq);
	try
	{
		std::cout << LIGHT_BLUE << "try to find 5" << RESET << std::endl;
		std::cout << GREEN << "Result: " << *easyfind(deq, 5) << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	try
	{
		std::cout << LIGHT_BLUE << "try to find 1" << RESET << std::endl;
		std::cout << GREEN << "Result: " << *easyfind(deq, 1) << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}

	std::cout << YELLOW << BOLD << "----------------TEST LIST----------------" << RESET << std::endl;
	std::list<int> lis;
	lis.push_back(0);
	lis.push_back(1);
	lis.push_back(2);
	lis.push_back(3);
	lis.push_back(4);
	lis.push_back(5);
	std::cout << LIGHT_BLUE << "Print container content" << RESET << std::endl;
	::printContainer(lis);
	try
	{
		std::cout << LIGHT_BLUE << "try to find 5" << RESET << std::endl;
		std::cout << GREEN << "Result: " << *easyfind(lis, 5) << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	try
	{
		std::cout << LIGHT_BLUE << "try to find 1" << RESET << std::endl;
		std::cout << GREEN << "Result: " << *easyfind(lis, 1) << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}


	std::cout << YELLOW << BOLD << "----------------TEST CONST VECTOR----------------" << RESET << std::endl;
	//TODO const
	const std::vector<int> cvect(5, 42);
	std::cout << LIGHT_BLUE << "Print container content" << RESET << std::endl;
	::printContainer(cvect);
	try
	{
		std::cout << LIGHT_BLUE << "try to find 5" << RESET << std::endl;
		std::cout << GREEN << "Result: " << *easyfind(cvect, 5) << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
	try
	{
		std::cout << LIGHT_BLUE << "try to find 42" << RESET << std::endl;
		std::cout << GREEN << "Result: " << *easyfind(cvect, 42) << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}
}