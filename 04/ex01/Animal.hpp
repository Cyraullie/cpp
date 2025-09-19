/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:18:21 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/19 14:14:30 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"


class Animal
{
	private:
		std::string _type;
	
	public:
		Animal();
		Animal(const Animal& cpy);
		Animal& operator=(const Animal& src);
		virtual ~Animal();

		virtual void	makeSound() const;
		std::string	getType() const;
};

#endif