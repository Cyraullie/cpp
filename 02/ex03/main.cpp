/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:09:53 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/23 15:28:22 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main( void )
{
	const Point a(5, 5);
	const Point b(10, 5);
	const Point c(7, 15);
	const Point point_in(6, 8);
	const Point point_out(-5, 20);

	std::cout << "Point a = x: " << a.getX() << ", y: " << a.getY() << std::endl;
	std::cout << "Point b = x: " << b.getX() << ", y: " << b.getY() << std::endl;
	std::cout << "Point c = x: " << c.getX() << ", y: " << c.getY() << std::endl;
	std::cout << "Point point_in = x: " << point_in.getX() << ", y: " << point_in.getY() << std::endl;
	std::cout << "Point point_out = x: " << point_out.getX() << ", y: " << point_out.getY() << std::endl;
	if (bsp(a, b, c, point_in))
		std::cout << "The Point point_in is in the triangle" << std::endl;
	else
		std::cout << "The Point point_in isn't in the triangle" << std::endl;
	if (bsp(a, b, c, point_out))
		std::cout << "The Point point_out is in the triangle" << std::endl;
	else
		std::cout << "The Point point_out isn't in the triangle" << std::endl;
	return 0;
}