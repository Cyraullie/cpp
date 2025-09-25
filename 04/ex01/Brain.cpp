/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:02:46 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/25 15:30:14 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(): _ideas(), _nbIdea(0)
{
	std::cout << "Brain has been created" << std::endl;
}
Brain::Brain(const Brain& cpy)
{
	for (int i = 0; i < MAX_IDEA; i++)
		this->_ideas[i] = cpy._ideas[i];
}

Brain::~Brain()
{
	std::cout << "Brain is dead D:" << std::endl;
}

Brain &Brain::operator=(const Brain &src)
{
	if (this != &src)
	{
		for (int i = 0; i < MAX_IDEA; i++)
			this->_ideas[i] = src._ideas[i];
	}
	std::cout << "Assignment operator Brain called" << std::endl;
	return (*this);
}

void	Brain::addIdea(std::string idea)
{
	if (this->_nbIdea < MAX_IDEA)
	{
		this->_ideas[this->_nbIdea++] = idea;
	}
	else
		std::cout << "Brain is full" << std::endl;
}

std::string	Brain::getIdea(int id) const
{
	return (this->_ideas[id]);
}
