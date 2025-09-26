/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:56:36 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/26 13:54:06 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap
{
	protected:
		std::string	_name;
		int			_hp;
		int			_energy;
		int			_damage;

		static const unsigned int _initial_hp = 10;
		static const unsigned int _initial_energy = 10;
		static const unsigned int _initial_damage = 0;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap(const ClapTrap& src);
		ClapTrap &operator=(const ClapTrap& cpy);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		std::string getName() const;
		int			getHP() const;
		int			getEnergy() const;
		int			getDamage() const;
};

#endif