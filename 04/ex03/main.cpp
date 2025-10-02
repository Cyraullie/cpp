/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:40:02 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/02 11:55:03 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	ICharacter* bob = new Character("bob");
	
	AMateria* tmp;
	
	std::cout << "0" << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	
	std::cout << "1" << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;

	return 0;
}