NAME=push_swap
CFLAGS=-Wall -Wextra -Werror
SOURCES=stack.c operations_a.c operations_b.c operations_both.c sorting_hat.c \
		cursive.c cleaning.c strjon.c str_clean.c new_sort.c op_list.c \
		new_sort_two.c sorting_hat_two.c tests.c
OBJ_FOLDER=out
LIBFT_DIR=../libft
OUT=$(addprefix $(OBJ_FOLDER)/,$(SOURCES:.c=.o))

all: $(LIBFT_DIR)/libft.a out/push_swap.o out/checker.o checker $(NAME) 

$(NAME): $(OUT) Sources/push_swap.c
	gcc $(CFLAGS) -o $(NAME) $(LIBFT_DIR)/libft.a out/push_swap.o $(OUT)

checker: $(OUT) Sources/checker.c
	gcc $(CFLAGS) -o checker $(LIBFT_DIR)/libft.a out/checker.o $(OUT)


$(LIBFT_DIR)/libft.a:
	@make -C $(LIBFT_DIR)

$(OBJ_FOLDER)/%.o: Sources/%.c Makefile ./Includes/ps.h
	@mkdir -p $(OBJ_FOLDER)
	gcc $(CFLAGS) -I Includes -I ../libft/includes -o $@ -c $<

clean:
	@make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_FOLDER)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	rm -rf $(NAME)
	rm -rf checker

re: fclean all