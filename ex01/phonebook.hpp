/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:02:18 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/07/29 16:25:43 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "contact.hpp"

class Phonebook
{
private:
	Contact phonebook[8];
	int		counter;
public:
	Phonebook();
	~Phonebook();
	void add_contact();
	void search_contact();
};
#endif
