/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:47:20 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/16 10:04:31 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>
#include <bits/stdc++.h> 

std::string ft_replace(std::string buffer, char *src, char *dst)
{
	std::string s1(src);
	std::string s2(dst);
	int n = 0;

	n = buffer.find(s1);
	while (n >= 0)
	{
		std::cout << buffer.substr(n, s1.length()) << std::endl;
		std::cout << n << std::endl;
		buffer.erase(n, s1.length());
		buffer.insert(n, s2);
		n = buffer.find(s1, n + s2.length());
	}
	return (buffer);

}

int main(int argc, char **argv)
{
	std::ifstream src;
	std::ofstream dest;
	std::string buffer;
	std::string file_name = argv[1];
	
	if (argc != 4)
	{
		std::cerr << "Please launch the programm with the expected arguments :" << std::endl;
		std::cerr << "./sed <filename> <s1> <s2>" << std::endl;		
		return (1);
	}
	src.open(file_name.c_str());
	if (!src.is_open())
	{
		std::cerr << "Please enter a valid name file" << std::endl;		
		return (1);
	}
	dest.open((file_name + ".replace").c_str());
	if (!dest.is_open())
	{
		std::cerr << "Error with the opening of dest.txt" << std::endl;		
		src.close();
		return (1);
	}
	while (std::getline (src, buffer)) {
		buffer = ft_replace(buffer, argv[2], argv[3]);
		dest << buffer;
		dest << std::endl;
	}

	src.close();
	dest.close();
	return 0;
}