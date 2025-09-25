/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 12:42:31 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/25 15:25:14 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main()
{
	Dog a;
	Dog b;
	Dog ca(a);

	std::cout << "*****TEST DEEP COPY AND OTHERS*****" << std::endl;
	std::cout << "a: " << a.getType() << " think: " << a.getBrain().getIdea(0) << std::endl;
	std::cout << "changing idea of b..." << std::endl;
	b.getBrain().addIdea("SLEEPING");
	std::cout << "b: " << b.getType() << " think: " << b.getBrain().getIdea(0) << std::endl;
	std::cout << "ca: " << ca.getType() << " think: " << ca.getBrain().getIdea(0) << std::endl;
	std::cout << "assignment of b to a..." << std::endl;
	a = b;
	std::cout << "a: " << a.getType() << " think: " << a.getBrain().getIdea(0) << std::endl;
	std::cout << "ca: " << ca.getType() << " think: " << ca.getBrain().getIdea(0) << std::endl;
	std::cout << "changing idea of b..." << std::endl;
	b.getBrain().addIdea("PLAYING");
	std::cout << "b: " << b.getType() << " think: " << b.getBrain().getIdea(0) << std::endl;
	std::cout << "a: " << a.getType() << " think: " << a.getBrain().getIdea(0) << std::endl;
	std::cout << "ca: " << ca.getType() << " think: " << ca.getBrain().getIdea(0) << std::endl;
}