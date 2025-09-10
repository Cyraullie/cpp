/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:29:37 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/09 15:26:03 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>
#include <cmath>
#include <iostream>

class Fixed
{
    private:
		int _fixedPoint;
		static const int _fract;
    public:
		Fixed();
		Fixed(const int n);
		Fixed(const float n);
		Fixed(const Fixed& copy);
		~Fixed();

		Fixed	&operator=(const Fixed& src);
		bool	operator>(const Fixed& src) const;
		bool	operator<(const Fixed& src) const;
		bool	operator>=(const Fixed& src) const;
		bool	operator<=(const Fixed& src) const;
		bool	operator==(const Fixed& src) const;
		bool	operator!=(const Fixed& src) const;
		Fixed	operator+(const Fixed& src) const;
		Fixed	operator-(const Fixed& src) const;
		Fixed	operator*(const Fixed& src) const;
		Fixed	operator/(const Fixed& src) const;
		Fixed	&operator++();
		Fixed	&operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		friend	std::ostream &operator<<(std::ostream &stream, const Fixed& fixed);
		static Fixed min(Fixed& a, Fixed& b);
		static const Fixed min(const Fixed& a, const Fixed& b);
		static Fixed max(Fixed& a, Fixed& b);
		static const Fixed max(const Fixed &a, const Fixed &b);
};


#endif