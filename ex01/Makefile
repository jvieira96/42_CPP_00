#v **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpedro-f <jpedro-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/28 11:34:09 by jpedro-f          #+#    #+#              #
#    Updated: 2025/07/29 14:07:40 by jpedro-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                NAMES & PATHS                                 #
#==============================================================================#

NAME = 	phonebook

SRCS =	contact.cpp \
		phonebook.cpp \
		main.cpp

OBJS =  $(SRCS:.cpp=.o)

#==============================================================================#
#                            FLAGS & COMMANDS                                  #
#==============================================================================#

C_COMP = c++

C_FLAGS = -Wall -Werror -Wextra -std=c++98

#==============================================================================#
#                                  COLORS                                      #
#==============================================================================#

RED			= \033[0;31m
GREEN		= \033[0;32m
YELLOW		= \033[0;33m	
RESET		= \033[0m

#==============================================================================#
#                                   RULES                                      #
#==============================================================================#

all: $(NAME)

%.o: %.cpp
	$(C_COMP) $(C_FLAGS) -c $< -o $@
	
$(NAME): $(OBJS)
	$(C_COMP) $(C_FLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)$(NAME) was created successfully!$(RESET)"

#==============================================================================#
#                                  CLEAN RULES                                 #
#==============================================================================#
clean:
	@$(RM) $(OBJS)
	@echo "$(RED)All .o files were deleted!$(RESET)"

fclean: clean 
	@$(RM) $(NAME)
	@echo "$(RED)$(NAME) was deleted!$(RESET)"
		
re: fclean all

.PHONY: all clean fclean re