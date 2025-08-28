/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:47:20 by cgoldens          #+#    #+#             */
/*   Updated: 2025/08/28 14:50:50 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	std::ifstream src;

	std::string s1;
	std::string s2;
	std::cout << argv[0]<< " " << argv[1]<< " " << argv[2]<< " " << argv[3] << std::endl;
	if (argc != 4)
	{
		std::cerr << "Please launch the programm with the excepted arguments :" << std::endl;
		std::cerr << "./sed <filename> <s1> <s2>" << std::endl;		
		return (1);
	}
	
	src.open(argv[1]);
	s1 = argv[2];
	s2 = argv[3];
	//src << "Writing this to a file.\n";
	src.close();
	return 0;
}