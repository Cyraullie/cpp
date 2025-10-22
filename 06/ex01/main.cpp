/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 14:23:39 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/22 15:39:12 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	uintptr_t raw;
	Data data;
	Data *newData = NULL;

	data.name = "patrick la trique";
	std::cout << "Data adress:" << &data << std::endl;
	std::cout << "value in Data before: " << data.name << std::endl;
	raw = Serializer::serialize(&data);
	std::cout << "Serialize: " << raw << std::endl;
	newData = Serializer::deserialize(raw);
	std::cout << "Deserialize: " << newData << std::endl;
	std::cout << "value in data after: " << newData->name << std::endl;
}