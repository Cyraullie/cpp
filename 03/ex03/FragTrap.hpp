/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 15:22:59 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/26 14:06:23 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		~FragTrap();
		FragTrap(const FragTrap& src);
		FragTrap &operator=(const FragTrap& cpy);
		
		void	highFivesGuys(void);
		void	attack(const std::string &target);

	protected:
		static const unsigned int	_initial_hp = 100;
		static const unsigned int	_initial_energy = 100;
		static const unsigned int	_initial_damage = 30;
};

#endif