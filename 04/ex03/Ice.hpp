/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:05:44 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/30 15:37:23 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice: public AMateria
{
	private:

	public:
		Ice();
		Ice(const Ice& cpy);
		~Ice();
		Ice &operator=(const Ice& src);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif