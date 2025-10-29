/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:45:35 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/29 15:22:29 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Default constructor
Span::Span() : _N(0)
{
	std::cout << GREEN << "Default Span constructor called" << RESET << std::endl;
}

// Data constructor
Span::Span(unsigned int n) : _N(n)
{
	std::cout << LIGHT_GREEN << "Span constructor called " << RESET << std::endl;
}

// Copy constructor
Span::Span(const Span& cpy) : _N(cpy._N)
{
	std::cout << LIGHT_GREEN << "Span copy constructor called " << RESET << std::endl;
}

// Destructor
Span::~Span()
{
	std::cout << RED << "Span destructor called " << RESET << std::endl;
};

// Copy assignment
Span& Span::operator=(const Span& src)
{
	std::cout << LIGHT_GREEN << "Span assignment operator called" << RESET << std::endl;
	if (this != &src) {
		this->_N = src._N;
	}
	return *this;
}

void Span::addNumber(int n)
{
	if (this->_multiset.size() < this->_N)
		this->_multiset.insert(n);
	else
		throw std::length_error(RED "Error, multiset is full" RESET);
}

void printNum(const int it)
{
	std::cout << it << " ";
}

void Span::printMultiset() const
{
	std::cout << "multiset: ";
	std::for_each(this->_multiset.begin(), this->_multiset.end(), printNum);
	std::cout << std::endl << "size : " << this->_multiset.size() << std::endl;
	std::cout << std::endl;
}

unsigned int Span::shortestSpan()
{
	
	printMultiset();
	return (0);
}

unsigned int Span::longestSpan()
{
	return (0);
}
