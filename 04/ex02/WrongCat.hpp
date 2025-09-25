/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:32:04 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/12 13:37:39 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	private:
		std::string type;
	
	public:
		WrongCat();
		WrongCat(const WrongCat& cpy);
		WrongCat& operator=(const WrongCat& src);
		~WrongCat();

		void	makeSound() const;
};

#endif