/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:13:37 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/24 15:37:16 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(): _content(), _size(0)
{
	std::cout << GREEN << "Default Array constructor called" << RESET << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n): _size(n)
{
	if (n > 0)
		this->_content = new T[n];
	else
		this->_content = 0;
	std::cout << LIGHT_GREEN << "Array of size " << n << " constructor called" << RESET << std::endl;
}

template <typename T>
Array<T>::Array(const Array& cpy): _size(cpy._size)
{
	if (cpy._size <= 0)
	{
		this->_content = 0;
		return ;
	}
	this->_content = new T[cpy._size]();
	for (size_t i = 0; i < cpy._size; i++)
	{
		this->_content[i] = cpy._content[i];
	}
	std::cout << LIGHT_GREEN << "Array copy constructor called " << RESET << std::endl;
}

template <typename T>
Array<T>::~Array()
{
	if (this->_content)
		delete[] this->_content;
	std::cout << RED << "Array destructor called" << RESET << std::endl;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array& src)
{
	if (this == &src)
		return (*this);
		
	delete[] this->_content;
	this->_content = 0;

	if (src._size <= 0)
	{
		this->_content = 0;
		return (*this);
	}
	
	this->_content = new T[src._size]();
	this->_size = src._size;

	for (size_t i = 0; i < src._size; i++)
	{
		this->_content[i] = src._content[i];
	}
	std::cout << LIGHT_GREEN << "Array assignment operator called " << RESET << std::endl;
	return (*this);
}

template <typename T>
T &Array<T>::operator[](size_t idx)
{
	if (idx >= this->_size)
		throw std::out_of_range("Index out of range");
	std::cout << CYAN << "Array [] operator called" << RESET << std::endl;
	return (this->_content[idx]);
}

template <typename T>
const T &Array<T>::operator[](size_t idx) const
{
	if (idx >= this->_size)
		throw std::out_of_range("Index out of range");
	std::cout << CYAN << "Array [] operator called" << RESET << std::endl;
	return (this->_content[idx]);
}

template <typename T>
unsigned int Array<T>::size()
{
	return (this->_size);
}

template <typename T>
void Array<T>::printContent()
{
	for (size_t i = 0; i < this->_size; i++)
	{
		std::cout << this->_content[i] << std::endl;
	}
}
