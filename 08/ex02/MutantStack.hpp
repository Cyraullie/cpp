/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 14:18:40 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/31 11:47:04 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template<typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack& cpy);
		~MutantStack();
		MutantStack &operator=(const MutantStack& src);
	
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		reverse_iterator rbegin();
		reverse_iterator rend();
};

# include "MutantStack.tpp"

#endif