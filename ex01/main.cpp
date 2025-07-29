/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:31:11 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/07/29 17:32:11 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "contact.hpp"
#include "phonebook.hpp"

int	main(void)
{
	Phonebook phonebook;
	std::string choice;

	while (1)
	{
		std::cout << "Welcome to the Phonebook manager write one of the options:" << std::endl;
		std::cout << "'ADD' to save a new contact." << std::endl;
		std::cout << "'SEARCH' to display a specific contact." << std::endl;
		std::cout << "'EXIT' to close." << std::endl;
		std::getline(std::cin, choice);
		while (choice != "EXIT" && choice != "ADD" && choice != "SEARCH")
		{
			std::cout << "Invalid choice try again: ";
			std::getline(std::cin, choice); 
		}
		if (choice == "ADD")
			phonebook.add_contact();
		if (choice == "SEARCH")
		{
			phonebook.search_contact();
		}
		if (choice == "EXIT")
			break;
	}
	return 0;
}
