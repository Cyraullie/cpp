/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:22:00 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/12 13:32:37 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{
	private:
		std::string type;
	
	public:
		Cat();
		Cat(const Cat& cpy);
		Cat& operator=(const Cat& src);
		~Cat();

		void	makeSound() const;
};

#endif