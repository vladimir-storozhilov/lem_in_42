NAME = lem-in

LIBFT_DIR = ./libft/
LIBFT = lft
PRINTF_DIR = ./ft_printf/
PRINTF = lftprintf

INCL_DIR = ./includes/
INCL_H = lem_in.h
INCL = $(addprefix $(INCL_DIR),$(INCL_H))

SRC_DIR = src/
SRC_C = lem_atoi.c lem_in_bfs.c lem_in_bfs_2.c lem_in_bfs_3.c\
		lem_in_bfs_expand.c lem_split.c main.c move_ants_1.c\
		lem_in_bfs_expand_2.c lem_in_bfs_expand_3.c\
		lem_in_bfs_expand_4.c lem_in_bfs_expand_5.c\
		lem_in_bfs_expand_6.c\

SRC = $(addprefix $(SRC_DIR),$(SRC_C))

FLAGS =	-Wall -Werror -Wextra

all: $(LIBFT_DIR)$(LIBFT) $(PRINTF_DIR)$(PRINTF) $(NAME)

$(LIBFT_DIR)$(LIBFT):
	make -C $(LIBFT_DIR)

$(PRINTF_DIR)$(PRINTF):
	make -C $(PRINTF_DIR)

$(NAME): $(SRC) $(INCL)
	gcc $(FLAGS) $(SRC) -I$(INCL_DIR) -L$(LIBFT_DIR) -$(LIBFT) -L$(PRINTF_DIR) -$(PRINTF) -o $(NAME)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(PRINTF_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean flcean re
