/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:56:36 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/10 16:26:29 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class ClapTrap
{
private:
	std::string	_name;
	int			_hp;
	int			_energy;
	int			_damage;
public:
	ClapTrap(std::string name);
	~ClapTrap();

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string getName();
	int getDamage();
};
