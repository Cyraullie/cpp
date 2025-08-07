/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:37:43 by cgoldens          #+#    #+#             */
/*   Updated: 2025/08/07 13:48:56 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact{
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;
		
	public:
		void		set_firstName(std::string firstName);
		void		set_lastName(std::string lastName);
		void		set_nickName(std::string nickName);
		void		set_phoneNumber(std::string phoneNumber);
		void		set_darkestSecret(std::string darkestSecret);
		std::string	get_firstName();
		std::string	get_lastName();
		std::string	get_nickName();
		std::string	get_phoneNumber();
		std::string	get_darkestSecret();
};

#endif
