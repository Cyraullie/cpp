/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:01:55 by cgoldens          #+#    #+#             */
/*   Updated: 2025/08/26 14:16:31 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <string>
# include <iostream>

int main(void)
{
    std::string stringVAL = "HI THIS IS BRAIN";
    std::string *stringPTR = &stringVAL;
    std::string &stringREF = stringVAL;
    std::cout << "memory address :" << std::endl;
    std::cout << "string value     : " << &stringVAL << std::endl;
    std::cout << "string pointer   : " << stringPTR << std::endl;
    std::cout << "string reference : " << &stringREF << std::endl;
    std::cout << "value :" << std::endl;
    std::cout << "string value     : " << stringVAL << std::endl;
    std::cout << "string pointer   : " << *stringPTR << std::endl;
    std::cout << "string reference : " << stringREF << std::endl;


}