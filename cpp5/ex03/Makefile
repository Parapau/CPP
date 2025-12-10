# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/02 12:53:07 by pafranco          #+#    #+#              #
#    Updated: 2025/12/10 13:53:35 by pafranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Bureaucracy
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -g -std=c++98
RM			= rm -rf

SRCDIR = 	src/
OBJDIR = 	obj/

FILES		= main Bureaucrat AForm PresidentialPardon RobotomyRequest ShrubberyCreationForm

SRC			= $(addprefix $(SRCDIR), $(FILES:=.cpp))
OBJ			= $(addprefix $(OBJDIR), $(FILES:=.o))
DEPS		= $(addprefix $(OBJDIR), $(FILES:=.d))
HEADER		= Bureaucrat.hpp AForm.hpp PresidentialPardon.hpp RobotomyRequest.hpp ShrubberyCreationForm.hpp

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
