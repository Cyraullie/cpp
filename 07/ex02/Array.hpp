/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:08:34 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/24 13:56:59 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <cstdlib> 
# include <iostream> 
# include "colors.hpp"

template <typename T>
class Array
{
	private:
		T		*_content;
		size_t	_size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array& cpy);
		~Array();

		Array	&operator=(const Array& src);
		T 		&operator[](size_t idx);
		const T	&operator[](size_t idx) const;
		
		unsigned int	size();
		void			printContent();
};

#endif