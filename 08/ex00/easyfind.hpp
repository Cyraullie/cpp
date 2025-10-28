/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:47:26 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/28 15:37:09 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include "colors.hpp"
# include <vector>
# include <deque>
# include <list>
# include <algorithm>

template <typename T> typename T::iterator	easyfind(T &container, int i);
template <typename T> typename T::const_iterator	easyfind(T const &container, int i);

template<typename T> void	printContainer(T cont);

class notFoundException : public std::exception
{
	public:
		virtual const char *what() const throw(){return ("Number not found in the container");};
};

#endif