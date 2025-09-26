/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:42:31 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/26 11:46:04 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
// const AAnimal a; 
	// abstract class can't be instancied
	//const AAnimal* i = new Dog();
	//const AAnimal* j = new Cat();
	
	std::cout << "----------" << std::endl;
	Dog realdog;
	if (realdog)
	{
		realdog->getBrain()->addIdeas("play with a ball");
	}
	Cat realcat;
	if (realcat)
	{
		realcat->getBrain()->addIdeas("be usefull");
	}
	std::cout << "----------" << std::endl;

	delete i;
	delete j;

	std::cout << "<-------------------------------------------->" << std::endl;

	int	nbr = 4;

	const AAnimal* Animals[nbr];

	for (int i = 0; i != nbr; i++)
	{
		if ((i % 2) == 0)
			Animals[i] = new Dog();
		else
			Animals[i] = new Cat();
	}
	std::cout << "--------deleting---------" << std::endl;
	for (int i = 0; i != nbr; i++)
	{
		delete Animals[i];
	}
}