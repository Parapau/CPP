# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pafranco <pafranco@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/02 12:53:07 by pafranco          #+#    #+#              #
#    Updated: 2025/07/02 12:53:25 by pafranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRC = megaphone.cpp
OBJ = $(addprefix obj/, $(SRC:%.cpp=%.o))
CC = c++
RM = rm -rf
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all:		dir $(NAME)

dir:
				mkdir -p obj

obj/%.o:		%.cpp Makefile
				$(CC) $(CPPFLAGS) -c $< -o $@

$(NAME):	$(OBJ)
				$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
				$(RM) obj

fclean:		clean
				$(RM) $(NAME)

re: 		fclean all

.PHONY: all clean fclean re dir
