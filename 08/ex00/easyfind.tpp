/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 14:21:17 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/28 15:42:00 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

template <typename T>
typename T::iterator	easyfind(T &container, int i)
{
	typename T::iterator n = std::find(container.begin(), container.end(), i);
	if (n == container.end())
		throw (::notFoundException());
	return (n);
}
template <typename T>
typename T::const_iterator	easyfind(T const &container, int i)
{
	typename T::const_iterator n = std::find(container.begin(), container.end(), i);
	if (n == container.end())
		throw (::notFoundException());
	return (n);
}

template<typename T>
void	printContainer(T container)
{
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}
