NAME=push_swap
CFLAGS=-Wall -Wextra -Werror
SOURCES=stack.c operations_a.c operations_b.c operations_both.c sorting_hat.c \
		cursive.c cleaning.c strjon.c str_clean.c new_sort.c op_list.c \
		main.c new_sort_two.c sorting_hat_two.c
OBJ_FOLDER=out
LIBFT_DIR=../libft
OUT=$(addprefix $(OBJ_FOLDER)/,$(SOURCES:.c=.o))

all: $(OUT) $(NAME)

$(NAME): $(LIBFT_DIR)/libft.a $(OUT)
	gcc $(CFLAGS) -o $(NAME) $(LIBFT_DIR)/libft.a $(OUT)

$(LIBFT_DIR)/libft.a:
	@make -C $(LIBFT_DIR)

$(OBJ_FOLDER)/%.o: Sources/%.c
	@mkdir -p $(OBJ_FOLDER)
	gcc $(CFLAGS) -I Includes -I ../libft/includes -o $@ -c $<

clean:
	@make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_FOLDER)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)

re: fclean all
