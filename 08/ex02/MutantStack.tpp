/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:18:38 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/31 13:09:57 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(): std::stack<T>()
{
	std::cout << GREEN << "Default MutantStack constructor called" << RESET << std::endl;
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& cpy): std::stack<T>(cpy)
{
	std::cout << LIGHT_GREEN << "MutantStack copy constructor called " << RESET << std::endl;
}

template<typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << RED << "MutantStack destructor called " << RESET << std::endl;
}

template<typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack& src)
{
	std::cout << LIGHT_GREEN << "MutantStack assignment operator called" << RESET << std::endl;
	if (this != &src) {
		this->c = src.c;
	}
	return *this;
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return (this->c.end());
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin()
{
	return (this->c.rbegin());
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend()
{
	return (this->c.rend());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const
{
	return (this->c.begin());
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const
{
	return (this->c.end());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const
{
	return (this->c.rbegin());
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const
{
	return (this->c.rend());
}