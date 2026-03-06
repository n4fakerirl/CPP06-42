# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ocviller <ocviller@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/05 13:52:06 by ocviller          #+#    #+#              #
#    Updated: 2026/03/06 13:55:15 by ocviller         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = c++
CFLAGS = -std=c++98 -Wall -Werror -Wextra
NAME = convert
SRC = main.cpp ScalarConverter.cpp ConvertChar.cpp ConvertInt.cpp ConvertFloat.cpp ConvertDouble.cpp Parse.cpp
OBJ = main.o ScalarConverter.o ConvertChar.o ConvertInt.o ConvertFloat.o ConvertDouble.o Parse.o
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