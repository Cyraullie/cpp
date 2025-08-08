/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:57:38 by cgoldens          #+#    #+#             */
/*   Updated: 2025/08/08 11:49:01 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <string>
# include <iomanip>
# include <cstdlib>
# include "Contact.hpp"

# define MAX_CONTACTS 8
# define MAX_LENGTH 10

class PhoneBook{
	private:
		Contact contacts[MAX_CONTACTS];

	public:
		void 	addContact(int id);
		void	searchContact();
};

#endif