/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:41:20 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/09 15:32:08 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::_fract = 8;

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

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_fixedPoint = copy.getRawBits();
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed& src)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &src)
		this->_fixedPoint = src.getRawBits();
	return (*this);
}




int		Fixed::getRawBits(void) const
{
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(int const raw)
{
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

Fixed min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

Fixed max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed max(const Fixed &a, const Fixed &b)
{
	return (a > b ? a : b);
}

