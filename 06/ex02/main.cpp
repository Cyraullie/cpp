/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:43:11 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/22 15:45:50 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <unistd.h>

int main(void)
{
	Base *objectPoint = generate();
	usleep(500000);
	Base &objectRef = *generate();

	identify(objectPoint);
	identify(*objectPoint);
	identify(objectRef);
	identify(&objectRef);

	delete objectPoint;
	delete &objectRef;
}