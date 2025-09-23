/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 13:16:43 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/23 14:38:58 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): _x(0), _y(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float x, const float y): _x(x), _y(y)
{
	//std::cout << "Float constructor called" << std::endl;
}

Point::Point(const Point& cpy): _x(cpy._x), _y(cpy._y)
{
	//std::cout << "Copy constructor called" << std::endl;
}

Point::~Point()
{
	//std::cout << "Destructor called" << std::endl;
}

Point &Point::operator=(const Point&)
{
	return (*this);
}

Fixed Point::getX(void) const
{
	return (this->_x);
}

Fixed Point::getY(void) const
{
	return (this->_y);
}
