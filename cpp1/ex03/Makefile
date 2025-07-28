# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/02 12:53:07 by pafranco          #+#    #+#              #
#    Updated: 2025/07/28 20:25:58 by pafranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ohTheHumanity
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -g -std=c++98
RM			= rm -rf

SRCDIR = 	src/
OBJDIR = 	obj/

FILES		= main Weapon HumanA HumanB

SRC			= $(addprefix $(SRCDIR), $(FILES:=.cpp))
OBJ			= $(addprefix $(OBJDIR), $(FILES:=.o))
DEPS		= $(addprefix $(OBJDIR), $(FILES:=.d))
HEADER		= Weapon.hpp HumanA.hpp HumanB.hpp

all: $(NAME)

$(NAME): $(OBJ)
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
