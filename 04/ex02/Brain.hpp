/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 14:02:44 by cgoldens          #+#    #+#             */
/*   Updated: 2025/09/25 14:41:34 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>
# define MAX_IDEA 100

class Brain
{
	private:
		std::string _ideas[MAX_IDEA];
		int			_nbIdea;
	public:
		Brain();
		Brain(const Brain& cpy);
		~Brain();
		Brain &operator=(const Brain &src);

		void		setIdea(int id, std::string idea);
		void		addIdea(std::string idea);
		std::string	getIdea(int id) const;
};

#endif