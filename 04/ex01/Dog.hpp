/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:21:22 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/25 15:02:20 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
	private:
		Brain *_brain;
	
	public:
		Dog();
		Dog(const Dog& cpy);
		Dog& operator=(const Dog& src);
		~Dog();

		void	makeSound() const;
		Brain	&getBrain();
};

#endif