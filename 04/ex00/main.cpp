/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:42:31 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/12 13:30:01 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	
	std::cout << "----------------------------------------------------" << std::endl;
	
	delete meta;
	delete i;
	delete j;
	
	std::cout << "----------------------------------------------------" << std::endl;

	const WrongAnimal* wrong = new WrongCat();
	const WrongCat* abomination = new WrongCat();

	std::cout << wrong->getType() << ": wrong noise" << std::endl;
	wrong->makeSound();
	std::cout << "<-------->"  << std::endl;
	std::cout << abomination->getType() << ": abomination noise" << std::endl;
	abomination->makeSound();

	std::cout << "----------------------------------------------------" << std::endl;
	delete wrong;
	delete abomination;
	
	return 0;
}