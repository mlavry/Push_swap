NAME = push_swap
CHECKER = checker

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(SUBDIR)

SRC = main.c stack_init.c error.c push_command.c rotate_command.c \
sort_three.c stack_utils.c rrotate_command.c swap_command.c init_a_to_b.c \
init_b_to_a.c sort_stacks.c push_cost.c

SRC_BONUS = Bonus/checker.c Bonus/get_next_line.c Bonus/get_next_line_utils.c \
push_command.c rotate_command.c rrotate_command.c swap_command.c init_a_to_b.c \
push_cost.c stack_utils.c error.c sort_three.c stack_init.c Bonus/error_instruction.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
SUBDIR = Libft

RED		:= \033[0;31m
GREEN	:= \033[0;32m
YELLOW	:= \033[0;33m
BLUE	:= \033[0;34m
NC		:= \033[0m

all: $(NAME)

$(NAME): $(SUBDIR)/libft.a $(OBJ)
	$(CC)	$(CFLAGS)	$(OBJ)	$(SUBDIR)/libft.a -o	$(NAME)
	@echo "$(GREEN)FINISHED COMPILING $(NAME)!$(NC)"

bonus: $(CHECKER)

$(CHECKER): $(SUBDIR)/libft.a $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(SUBDIR)/libft.a -o $(CHECKER)
	@echo "$(GREEN)FINISHED COMPILING BONUS CHECKER!$(NC)"

$(SUBDIR)/libft.a:
	$(MAKE) -C $(SUBDIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	$(MAKE) -C $(SUBDIR) clean
	@echo "$(YELLOW)OBJECTS FILES DELETED!$(NC)"

fclean: clean
	rm -f $(NAME) $(CHECKER)
	$(MAKE) -C $(SUBDIR) fclean
	@echo "$(RED)ALL FILES CLEAN!$(NC)"

re: fclean all

.PHONY: all bonus clean fclean re
