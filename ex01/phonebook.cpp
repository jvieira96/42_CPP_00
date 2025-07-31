/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:34:06 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/07/31 14:53:53 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include.hpp"

/*--------------------INPUT VALIDATION---------------------------------*/

std::string trim(std::string input)
{
	int end = input.length() - 1;
	int start = 0;

	while (start <= end && std::isspace(input[start]))
		start++;
	while (end >= start && std::isspace(input[end]))
		end--;
	return input.substr(start, end - start + 1);
}

bool non_alpha(std::string input)
{
	int i = -1;

	while (input[++i])
	{
		if (!std::isalpha(input[i]) && !std::isspace (input[i]))
			return true;
	}
	return false;
}

bool non_numeric(std::string input)
{
	int i = -1;

	while (input[++i])
	{
		if (!std::isdigit(input[i]))
			return true;
	}
	return false;
}

bool	only_whitespaces(std::string input)
{
	int i = -1;

	while (input[++i])
	{
		if (!std::isspace(input[i]))
			return false;
	}
	return (true);
}

bool	invalid_input(std::string input, int flag)
{
	if (input.empty() || only_whitespaces(input))
	{
		std::cout << RED << "error: empty input" << RESET << std::endl;
		return true;
	}
	if (flag == 0)
	{
		if (non_alpha(input))
			{
				std::cout << RED << "error: only alphabetic characters" << RESET << std::endl;
				return true;
			}
	}
	if (flag == 1)
	{
		if (non_numeric(input))
		{
			std::cout << RED << "error: only numeric characters" << RESET << std::endl;
			return true;
		}
	}
	return false;
}

std::string get_valid_input(const std::string prompt, int flag)
{
	std::string input;
	
	std::cout << prompt;
	std::getline(std::cin, input);
	CHECK_EOF(input);
	while (invalid_input(input, flag))
	{
		std::cout << RED << "Invalid input, try again: " << RESET;
		std::getline(std::cin, input);
		CHECK_EOF(input);
	}
	input = trim(input);
	return (input);	
}

/*------------------------------Const/Destr--------------------------*/

PhoneBook::PhoneBook()
{
	this->index = 0;
	this->counter = 0;
}

PhoneBook::~PhoneBook()
{
	return;
}


/*----------------------------------SETTERS--------------------------*/

void PhoneBook::add_contact()
{
	Contact contact;

	contact.set_first_name(get_valid_input("First Name: ", 0));
	contact.set_last_name(get_valid_input("Last Name: ", 0));
	contact.set_nickname(get_valid_input("Nickname: ", 0));
	contact.set_phone_number(get_valid_input("Phone number: ", 1));
	contact.set_darkest_secret(get_valid_input("Darkest secret: ", 0));

	index =  index % 8;
	phonebook[index] = contact;
	index++;
	if (counter < 8)
		counter++;
}

std::string format_str(std::string str)
{
	if (str.length() <= 10)
		return str;
	return str.substr(0, 9) + ".";
}

/*-------------------------------PRINT FORMAT---------------------------------------*/

void PhoneBook::search_contact()
{
	std::string choice;
	int			choice_nbr;

	std::cout << GREEN << " ------------------------------------------- " << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << " ------------------------------------------- " << RESET << std::endl;
	for (int i = 0; i < counter; i++)
	{
		std::cout << GREEN << "|" << std::right << std::setw(10) << i + 1;
		std::cout << "|" << std::right << std::setw(10) << format_str(this->phonebook[i].get_first_name());
		std::cout << "|" << std::right << std::setw(10) << format_str(this->phonebook[i].get_last_name());
		std::cout << "|" << std::right << std::setw(10) << format_str(this->phonebook[i].get_nickname()) << "|" << RESET << std::endl;
	}
	std::cout << GREEN << " ------------------------------------------- " << RESET << std::endl;
	std::cout << BLUE << "Insert the index: " << RESET;
	while (true)
	{
		std::getline(std::cin, choice);
		CHECK_EOF(choice);
		if (std::cin.eof())
			return ;
		if(non_numeric(choice))
		{                                                             
			std::cout << RED << "Error: only numeric values, try again: " << RESET;
			continue;
		}
		choice_nbr =  std::atoi(choice.c_str());
		if (choice_nbr >= 1 && choice_nbr <= index)
			break;
		std::cout << RED << "Error: invalid, try again: " << RESET;
	}
	std::cout << "First Name: " << phonebook[choice_nbr - 1].get_first_name() << std::endl;
	std::cout << "Last Name: " << phonebook[choice_nbr - 1].get_last_name() << std::endl;
	std::cout << "Nickname: " << phonebook[choice_nbr - 1].get_nickname() << std::endl;
	std::cout << "Phone Number: " << phonebook[choice_nbr - 1].get_phone_number() << std::endl;
	std::cout << "Darkest Secrect: " << phonebook[choice_nbr - 1].get_darkest_secret() << std::endl;
}
