/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:18:21 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/25 15:06:16 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"


class Animal
{
	protected:
		std::string _type;
	
	public:
		Animal();
		Animal(std::string type);
		Animal(const Animal& cpy);
		Animal& operator=(const Animal& src);
		virtual ~Animal();

		virtual void	makeSound() const;
		virtual std::string	getType() const;
		virtual Brain &getBrain() const;
};

#endif