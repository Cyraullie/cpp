/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgoldens <cgoldens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 11:37:43 by cgoldens          #+#    #+#             */
/*   Updated: 2025/07/07 11:51:19 by cgoldens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>

class Contact{
    private:
        enum Field {
            FirstName,
            LastName,
            NickName,
            PhoneNumber,
            DarkestSecret,
        };
    public:
        Contact(void);
        ~Contact(void);

        bool    set_contact();
        void    get_contact(int index)const;
};
#endif