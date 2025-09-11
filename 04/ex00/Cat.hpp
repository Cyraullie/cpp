/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:22:00 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/11 17:22:09 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_HPP
# define Cat_HPP

#include "Animal.hpp"
#include <string>
#include <iostream>

class Cat: public Animal
{
	private:
		std::string type;
	
	public:
		void	makeSound();
};

#endif