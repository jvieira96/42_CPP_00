/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:31:11 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/07/30 15:23:33 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

int	main(void)
{
	PhoneBook 	phonebook;
	std::string choice;
	int			counter = 0;

	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	std::cout << YELLOW << "Welcome to the Phonebook manager write one of the options:" << RESET << std::endl;
	std::cout << YELLOW << "'ADD' to save a new contact." << RESET << std::endl;
	std::cout << YELLOW << "'SEARCH' to display a specific contact." << RESET << std::endl;
	std::cout << YELLOW <<  "'EXIT' to close." << RESET << std::endl;

	while (1)
	{
		std::cout << BLUE << "Write option (ADD, SEARCH, EXIT): " << RESET;
		std::getline(std::cin, choice);
		CHECK_EOF(choice);
		while (choice != "EXIT" && choice != "ADD" && choice != "SEARCH")
		{
			std::cout << RED << "Invalid choice try again: " << RESET;
			std::getline(std::cin, choice);
			CHECK_EOF(choice);
		}
		if (choice == "ADD")
		{
			phonebook.add_contact();
			counter++;
		}
		if (choice == "SEARCH")
		{
			if (counter == 0)
				std::cout << RED << "Phonebook is empty" << RESET << std::endl;
			else
				phonebook.search_contact();
		}
		if (choice == "EXIT")
			break;
	}
	return 0;
}
