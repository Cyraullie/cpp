/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:53:03 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/30 15:57:07 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria *_materias[4];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& cpy);
		~MateriaSource();
		MateriaSource &operator=(const MateriaSource& src);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif