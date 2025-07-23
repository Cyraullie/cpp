/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:57:38 by cgoldens          #+#    #+#             */
/*   Updated: 2025/07/23 14:34:40 by cgoldens         ###   ########.fr       */
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
		int 	_num_entries;

	public:
		Contact contacts[MAX_CONTACTS];
		// Constructors
		PhoneBook();
		~PhoneBook();
		
		void addContact(std::string first_name, std::string last_name, std::string nick_name,
			std::string phone_number, std::string darkest_secret);
		Contact getContact(int id);
};

#endif