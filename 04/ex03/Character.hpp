/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 15:11:33 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/30 15:18:32 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include <string>

class Character: public ICharacter
{
	private:
		std::string _name;
		AMateria *_invertory[4];

	public:
		Character();
		Character(std::string name);
		Character(const Character& cpy);
		~Character();
		Character &operator=(const Character& src);
		
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);	
};

#endif