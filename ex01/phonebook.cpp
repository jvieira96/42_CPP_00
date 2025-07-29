/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:34:06 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/07/29 17:55:27 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "contact.hpp"
#include "phonebook.hpp"
#include <iomanip>
#include <cstdlib> 

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
		std::cout << "error: empty input" << std::endl;
		return true;
	}
	if (flag == 0)
	{
		if (non_alpha(input))
			{
				std::cout << "error: only alphabetic characters" << std::endl;
				return true;
			}
	}
	if (flag == 1)
	{
		if (non_numeric(input))
		{
			std::cout << "error: only numeric characters" << std::endl;
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

	while (invalid_input(input, flag))
	{
		std::cout << "Invalid input, try again: ";
		std::getline(std::cin, input);
	}
	input = trim(input);
	return (input);	
}

/*------------------------------Const/Destr--------------------------*/

Phonebook::Phonebook()
{
	this->counter = 1;
}

Phonebook::~Phonebook()
{
	return;
}


/*----------------------------------SETTERS--------------------------*/

void Phonebook::add_contact()
{
	Contact contact;
	int		index = 0;

	contact.set_first_name(get_valid_input("First Name: ", 0));
	contact.set_last_name(get_valid_input("Last Name: ", 0));
	contact.set_nickname(get_valid_input("Nickname: ", 0));
	contact.set_phone_number(get_valid_input("Phone number: ", 1));
	contact.set_darkest_secret(get_valid_input("Darkest secret: ", 0));

	index =  this->counter % 8;
	this->phonebook[index] = contact;
	this->counter++;
}

std::string format_str(std::string str)
{
	if (str.length() < 10)
		return str;
	return str.substr(0, 8) + ".";
}

void Phonebook::search_contact()
{
	std::string choice;
	int			choice_nbr;

	std::cout << " ------------------------------------------- " << std::endl;
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	std::cout << " ------------------------------------------- " << std::endl;
	for (int i = 1; i < this->counter; i++)
	{
		std::cout << "|" << std::right << std::setw(10) << i;
		std::cout << "|" << std::right << std::setw(10) << format_str(this->phonebook[i].get_first_name());
		std::cout << "|" << std::right << std::setw(10) << format_str(this->phonebook[i].get_last_name());
		std::cout << "|" << std::right << std::setw(10) << format_str(this->phonebook[i].get_nickname()) << "|" << std::endl;
	}
	std::cout << " ------------------------------------------- " << std::endl;
	std::cout << "Insert the index: ";
	while (true)
	{
		std::getline(std::cin, choice);
		if(non_numeric(choice))
		{                                                             
			std::cout << "Error: only numeric values, try again: ";
			continue;
		}
		choice_nbr =  std::atoi(choice.c_str());
		if (choice_nbr >= 1 && choice_nbr <= this->counter - 1)
			break;
		std::cout << "Error: Numeric from 1 to " << this->counter - 1 << " , try again: ";
	}
	std::cout << "First Name: " << phonebook[choice_nbr].get_first_name() << std::endl;
	std::cout << "Last Name: " << phonebook[choice_nbr].get_last_name() << std::endl;
	std::cout << "Nickname: " << phonebook[choice_nbr].get_nickname() << std::endl;
	std::cout << "Phone Number: " << phonebook[choice_nbr].get_phone_number() << std::endl;
	std::cout << "Darkest Secrect: " << phonebook[choice_nbr].get_darkest_secret() << std::endl;
}
