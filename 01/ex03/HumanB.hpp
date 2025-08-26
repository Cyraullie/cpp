/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:58:33 by cgoldens          #+#    #+#             */
/*   Updated: 2025/08/26 15:25:22 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <string>
#include "Weapon.hpp"

class HumanB
{
    private:
        std::string	_name;
        Weapon		*_weapon;
    public:
        HumanB(std::string name);
        void setWeapon(Weapon &weapon);
        void attack();
};

#endif