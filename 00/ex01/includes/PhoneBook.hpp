/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:57:38 by cgoldens          #+#    #+#             */
/*   Updated: 2025/08/07 13:32:24 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iomanip>
# include <cstdlib>
# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook{
	private:
		Contact contacts[MAX_CONTACTS];

	public:
		
		void	searchContact(int id);
		void 	addContact(int id);
};

#endif