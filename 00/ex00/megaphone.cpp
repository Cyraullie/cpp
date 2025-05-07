/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:07:20 by cgoldens          #+#    #+#             */
/*   Updated: 2025/05/07 15:40:45 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static std::string toUpperCase(std::string s)
{
	size_t	i;

	i = 0;
	while (i < s.size())
	{
		if ('a' <= s[i] && s[i] <= 'z')
			s[i] -= 32;
		i++;
	}
	return (s);
}

int main(int argc, char **argv)
{
	int 		i;
	std::string	s;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (i < argc)
		{
			s = argv[i];
			s = toUpperCase(s);
			std::cout << s;
			if (i == argc - 1)
				std::cout << std::endl;
			i++;
		}		
	}

	return (0);
}