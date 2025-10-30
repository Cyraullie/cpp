/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:18:40 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/30 15:47:03 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template<typename T>
class MutantStack : std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack& cpy);
		~MutantStack();
		MutantStack &operator=(const MutantStack& src);
	
		typedef typename std::stack<T>::container_type::iterator iterator;
};

# include "MutantStack.tpp"

#endif