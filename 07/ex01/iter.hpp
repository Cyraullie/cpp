/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:51:05 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/23 13:35:43 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
		
# include <cstdlib> 
# include <iostream> 

template <typename T>
void iter(const T *array, size_t const len, void (*f)(const T&))
{
	for (size_t i = 0; i < len; i++)
	{
		f(array[i]);
	}
}

template <typename T>
void iter(T *array, size_t const len, void (*f)(T&))
{
	for (size_t i = 0; i < len; i++)
	{
		f(array[i]);
	}
}

// ** FUNCTIONS TEST **

template<typename T>
void increment(T &elem)
{
	elem++;
}

template<typename T>
void print(T const &elem)
{
	std::cout << elem << std::endl;
}

#endif