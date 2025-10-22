/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 15:43:14 by cgoldens          #+#    #+#             */
/*   Updated: 2025/10/22 15:49:29 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <string>
# include <iostream>

class Base
{
	private:

	public:
		virtual ~Base() {};
};

// *** CHILD CLASSES ***

class A: public Base {};
class B: public Base {};
class C: public Base {};

// *** FUNCTIONS ***

Base *generate();
void identify(Base *p);
void identify(Base &p);

#endif // BASE_HPP
