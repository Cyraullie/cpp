/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:06:17 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/30 15:37:41 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure: public AMateria
{
	private:

	public:
		Cure();
		Cure(const Cure& cpy);
		~Cure();
		Cure &operator=(const Cure& src);

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif