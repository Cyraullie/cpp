/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:36:34 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/22 15:38:15 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <string>
# include <iostream>
# include <stdint.h>
# include "colors.hpp"

typedef struct Data_s
{
	std::string name;
}	Data;

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& cpy);
		~Serializer();
		Serializer &operator=(const Serializer& src);

	public:
		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif // SERIALIZER_HPP
