# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/02 12:53:07 by pafranco          #+#    #+#              #
#    Updated: 2026/02/24 12:57:45 by pafranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= RPN
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -g -std=c++98
RM			= rm -rf

SRCDIR = 	src/
OBJDIR = 	obj/

FILES		= main RPN

SRC			= $(addprefix $(SRCDIR), $(FILES:=.cpp))
OBJ			= $(addprefix $(OBJDIR), $(FILES:=.o))
DEPS		= $(addprefix $(OBJDIR), $(FILES:=.d))
HEADER		= RPN.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(CC) $(OBJ) -o $(NAME)
	@printf " - Executable ready.\n"

$(OBJDIR)%.o: $(SRCDIR)%.cpp $(HEADER) Makefile
	@mkdir -p $(OBJDIR)
	@$(CC) $(FLAGS) -c -MMD $< -o $@

clean:
	@$(RM) $(OBJDIR) $(OBJ)
	@printf " - Object files removed.\n"

fclean: clean
	@$(RM) $(NAME)
	@printf " - Executable removed.\n"

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
