/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 11:40:02 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/01 11:49:37 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

void subject_provided_test()
{
	IMateriaSource* src = new MateriaSource();
	Ice *ice = new Ice();
	Cure *cure = new Cure();
	src->learnMateria(ice);
	src->learnMateria(cure);
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	delete ice;
	delete cure;
}

void copy_constructor_test()
{
	IMateriaSource* src = new MateriaSource();
	Ice *ice = new Ice();
	Cure *cure = new Cure();
	src->learnMateria(ice);
	src->learnMateria(cure);
	Character me("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me.equip(tmp);
	tmp = src->createMateria("cure");
	me.equip(tmp);
	Character copy(me);
	me.unequip(0);
	me.use(0, copy);
	copy.use(0, me);
	delete src;
	delete ice;
	delete cure;
}

void assignment_operator_test()
{
	IMateriaSource* src = new MateriaSource();
	Ice *ice = new Ice();
	Cure *cure = new Cure();
	src->learnMateria(ice);
	src->learnMateria(cure);
	Character me("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me.equip(tmp);
	tmp = src->createMateria("cure");
	me.equip(tmp);
	Character copy;
	copy = me;
	me.unequip(0);
	me.use(0, copy);
	copy.use(0, me);
	delete src;
	delete ice;
	delete cure;
}

void invalid_arguments_test()
{
	IMateriaSource* src = new MateriaSource();
	Ice *ice = new Ice();
	Cure *cure = new Cure();
	src->learnMateria(ice);
	src->learnMateria(0);
	src->learnMateria(cure);
	src->learnMateria(cure);
	src->learnMateria(cure);
	src->learnMateria(cure);
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("nonexistant");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("ice");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->unequip(-1);
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(-1, *bob);
	delete bob;
	delete me;
	delete src;
	delete ice;
	delete cure;
}

int main()
{
	// subject_provided_test();
	// copy_constructor_test();
	// assignment_operator_test();
	invalid_arguments_test();
	return 0;
}