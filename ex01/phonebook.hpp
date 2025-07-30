/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:02:18 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/07/30 15:22:36 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "include.hpp"
#include "contact.hpp"

class PhoneBook
{
private:
	Contact phonebook[8];
	int		index;
	int 	counter;
public:
	PhoneBook();
	~PhoneBook();
	void add_contact();
	void search_contact();
};
#endif
