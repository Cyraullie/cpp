/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:18:38 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/31 11:49:34 by cgoldens         ###   ########.fr       */
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
