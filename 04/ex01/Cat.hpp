/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:22:00 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/18 14:58:45 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
		std::string type;
		Brain *brain;
	
	public:
		Cat();
		Cat(const Cat& cpy);
		Cat& operator=(const Cat& src);
		~Cat();

		void	makeSound() const;
};

#endif