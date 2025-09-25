/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 17:18:21 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/25 15:47:45 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>
# include <iostream>
# include "Brain.hpp"

class AAnimal
{
	protected:
		std::string _type;
	
	public:
		AAnimal();
		AAnimal(std::string type);
		AAnimal(const AAnimal& cpy);
		AAnimal& operator=(const AAnimal& src);
		virtual ~AAnimal();

		virtual void	makeSound() const = 0;
		virtual std::string	getType() const;
		virtual Brain &getBrain() const = 0;
};

#endif