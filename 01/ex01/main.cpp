/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:18:50 by cgoldens          #+#    #+#             */
/*   Updated: 2025/08/15 15:42:23 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *zombieArray;
	int N = 3;

	zombieArray = zombieHorde(N, "walker");
	for (int i = 0; i < N; i++)
	{
		std::cout << "Num: " << i << std::endl;
		zombieArray[i].announce();
		std::cout << std::endl;
	}
	delete[] zombieArray;
}