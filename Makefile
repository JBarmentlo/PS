NAME=Push_Swap
CFLAGS=-Wall -Wextra -Werror
SOURCES=stack.c operations_a.c operations_b.c operations_both.c sorting_hat.c \
		cursive.c opti.c cleaning.c strjon.c str_clean.c new_sort.c op_list.c \
		 main.c
OBJ_FOLDER=out
OUT=$(addprefix $(OBJ_FOLDER)/,$(SOURCES:.c=.o))

all: $(OUT) $(NAME)

$(NAME): $(OUT)
	gcc $(CFLAGS) -o $(NAME) $(OUT)

$(OBJ_FOLDER)/%.o: Sources/%.c
	@mkdir -p $(OBJ_FOLDER)
	gcc $(CFLAGS) -I Includes -I ../libft/includes -o $@ -c $<

clean:
	rm -rf $(OBJ_FOLDER)

fclean: clean
	rm -rf $(NAME)

re: fclean all
