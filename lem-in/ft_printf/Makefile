# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtapioca <gtapioca@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/17 13:58:43 by gtristan          #+#    #+#              #
#    Updated: 2020/03/31 00:24:40 by gtapioca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCL = includes/

SRC_DIR = src/
SRC_C = analysis.c decimal.c float2.c float4.c ft_printf.c parsing.c \
  		printnum.c services_itoa.c create_string.c float.c float3.c free.c \
		libfunctions.c oct.c print_color.c putchar_str.c string_char.c
SRC = $(addprefix $(SRC_DIR),$(SRC_C))

OBJ_DIR = obj/
OBJ_O = $(SRC_C:%.c=%.o)
OBJ = $(addprefix $(OBJ_DIR),$(OBJ_O))

FLAGS =	-Wall -Werror -Wextra

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(SRC) $(OBJ) 
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	gcc $(FLAGS) -I $(INCL) -o $@ -c $<

clean:
	rm -rf $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean flcean re
