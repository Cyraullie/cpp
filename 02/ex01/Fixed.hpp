/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:29:37 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/02 13:37:16 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <string>

class Fixed
{
    private:
		int _fixedPoint;
		static const int _fract = 8;
    public:
		Fixed();
		Fixed(const Fixed& copy);
		~Fixed();
		Fixed &operator=(const Fixed& src);
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif