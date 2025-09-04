/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:41:20 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/04 15:18:20 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(): _fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n): _fixedPoint(n << this->_fract)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n): _fixedPoint(roundf(n * (1 << Fixed::_fract)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	this->_fixedPoint = copy._fixedPoint;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& src)
{
	if (this != &src)
		this->_fixedPoint = src._fixedPoint;
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPoint = raw;
}

float Fixed::toFloat( void ) const
{
	return ((float)_fixedPoint / (1 << Fixed::_fract));
}

int Fixed::toInt( void ) const
{
	return (this->_fixedPoint >> Fixed::_fract);
}

std::ostream &operator<<(std::ostream &stream, const Fixed &fixed)
{
	stream << fixed.toFloat();
	return (stream);
}
