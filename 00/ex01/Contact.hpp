/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:37:43 by cgoldens          #+#    #+#             */
/*   Updated: 2025/07/17 10:48:51 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>

class Contact{
	private:
		static std::string	_fields_name[5];
		std::string			_informations[11];

		enum Field {
			FirstName = 0,
			LastName,
			NickName,
			PhoneNumber,
			DarkestSecret
		};
	public:
		Contact(void);
		~Contact(void);

		bool	set_contact();
		void	get_contact(int index)const;
};

#endif