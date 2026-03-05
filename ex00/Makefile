# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/05 13:52:06 by ocviller          #+#    #+#              #
#    Updated: 2026/03/05 14:31:20 by ocviller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -std=c++98 -Wall -Werror -Wextra
NAME = convert
SRC = main.cpp ScalarConverter.cpp
OBJ = main.o ScalarConverter.o
OPTIONS = -o $(NAME)

all: $(OBJ)
	@$(CC) $(CFLAGS) $(SRC) $(OPTIONS)

$(OBJ): $(SRC)
	@$(CC) $(CFLAGS) -c $(SRC)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re