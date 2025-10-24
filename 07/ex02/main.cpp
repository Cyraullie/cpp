/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:08:37 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/24 13:56:31 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.tpp"

int main(void)
{
	std::cout << BOLD << "*** TEST ASSIGNMENT OPERATOR ***" << RESET << std::endl;
	Array<int> a(5);
	Array<int> b(10);
	std::cout << "size of a: " << a.size() << ", size of b: " << b.size() << std::endl;
	std::cout << "b = a" << std::endl;
	a = b;
	std::cout << "size of a: " << a.size() << ", size of b: " << b.size() << std::endl;


	std::cout << BOLD << "*** TEST [] OVERLOAD OPERATOR" << RESET << std::endl;

	try
	{
		std::cout << "should works:" << std::endl;
		std::cout << "b[0] = 4 and b[1] = 2 and b[5] = 6" << std::endl;
		b[0] = 4;
		b[1] = 2;
		b[5] = 6;
		std::cout << "b[0]:" << b[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << '\n';
	}

	try
	{
		std::cout << "should not works" << std::endl;
		std::cout << "b[11] = 666" << std::endl;
		b[11] = 666;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	std::cout << BOLD << "*** TEST COPY CONSTRUCTOR ON B ***" << RESET << std::endl;
	Array<int> c(b);
	std::cout << "size of b: " << b.size() << ", size of c: " << c.size() << std::endl;
	std::cout << "content of b:" << std::endl;
	b.printContent();
	std::cout << "content of c:" << std::endl;
	c.printContent();

	std::cout << BOLD << "*** TEST WITH DEFAULT CONSTRUCTOR ***" << RESET << std::endl;

	Array<char> d;

	std::cout << "size of d: " << d.size() << std::endl;
	std::cout << "content of d:" << std::endl;
	d.printContent();

}