/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:14:54 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/26 14:08:20 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap(const ScavTrap& src);
		ScavTrap &operator=(const ScavTrap& cpy);
		
		void	guardGate();
		void	attack(const std::string& target);
	
	protected:
		static const unsigned int	_initial_hp = 100;
		static const unsigned int	_initial_energy = 50;
		static const unsigned int	_initial_damage = 20;
};

#endif