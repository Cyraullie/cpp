/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:53:03 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/01 13:39:33 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# define MAX_MATERIAS 4

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria *_materias[MAX_MATERIAS];
	public:
		MateriaSource();
		MateriaSource(const MateriaSource& cpy);
		~MateriaSource();
		MateriaSource &operator=(const MateriaSource& src);
		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif