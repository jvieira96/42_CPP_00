/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   include.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 15:02:48 by jpedro-f          #+#    #+#             */
/*   Updated: 2025/07/30 15:19:38 by jpedro-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDE_HPP
# define INCLUDE_HPP

#include "contact.hpp"
#include "phonebook.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <signal.h>

#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define RESET   "\033[0m"

#define CHECK_EOF(str) \
    if (!std::cin) \
	{ \
        std::cerr << RED << "EOF reached or input error. Exiting program." << RESET << std::endl; \
        exit(EXIT_FAILURE); \
    }
	
#endif
