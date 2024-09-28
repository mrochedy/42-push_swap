NAME = push_swap

BONUS = checker

LIBFT = ./libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJS_DIR = objs

SRCS = push_swap.c \
	tools.c \
	stack_tools.c \
	ft_strjoin_argv.c \
	operations.c \
	operations2.c \
	algorithm.c \
	algo_calculations_to_a.c \
	algo_calculations_to_b.c \
	algo_tools.c \
	algo_tools2.c
BONUS_SRCS = bonus/checker_bonus.c \
	bonus/tools_bonus.c \
	bonus/stack_tools_bonus.c \
	bonus/ft_strjoin_argv_bonus.c \
	bonus/operations_bonus.c \
	bonus/operations2_bonus.c \
	bonus/check_operations_bonus.c

OBJS = $(SRCS:%.c=$(OBJS_DIR)/%.o)
BONUS_OBJS = $(BONUS_SRCS:%.c=$(OBJS_DIR)/%.o)

# ANSI color codes
GREEN = \033[1;32m
YELLOW = \033[1;33m
WHITE = \033[1;97m
BLUE = \033[1;34m
CYAN = \033[1;36m
RED = \033[1;31m
RESET = \033[0m

COL1 = \033[38;2;255;204;153m # Orange pastel
COL2 = \033[38;2;255;214;140m # Orange clair pastel
COL3 = \033[38;2;255;224;128m # Orange-jaune pastel
COL4 = \033[38;2;255;234;115m # Jaune-orangé pastel
COL5 = \033[38;2;255;244;102m # Jaune clair pastel
COL6 = \033[38;2;255;255;153m # Jaune pastel

all: $(LIBFT) $(NAME)
bonus: $(LIBFT) $(BONUS)

$(OBJS_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@printf "$(CYAN)Compiling $<...$(RESET)\n"
	@$(CC) $(CFLAGS) -c $< -o $@ 

$(LIBFT):
	@make -C ./libft

$(NAME): $(OBJS)
	@printf "\n$(YELLOW)Linking objects...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "$(BLUE)Progress: 100%$(RESET)"
	@printf "$(GREEN)Compilation complete!$(RESET)\n"
	@printf "\n$(COL1)██████╗ ██╗   ██╗███████╗██╗  ██╗        ███████╗██╗    ██╗ █████╗ ██████╗ \n"
	@printf "$(COL2)██╔══██╗██║   ██║██╔════╝██║  ██║        ██╔════╝██║    ██║██╔══██╗██╔══██╗\n"
	@printf "$(COL3)██████╔╝██║   ██║███████╗███████║        ███████╗██║ █╗ ██║███████║██████╔╝\n"
	@printf "$(COL4)██╔═══╝ ██║   ██║╚════██║██╔══██║        ╚════██║██║███╗██║██╔══██║██╔═══╝ \n"
	@printf "$(COL5)██║     ╚██████╔╝███████║██║  ██║███████╗███████║╚███╔███╔╝██║  ██║██║     \n"
	@printf "$(COL6)╚═╝      ╚═════╝ ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝ ╚══╝╚══╝ ╚═╝  ╚═╝╚═╝     $(RESET)\n\n"

$(BONUS): $(BONUS_OBJS)
	@printf "\n$(YELLOW)Linking objects...$(RESET)\n"
	@$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS)
	@echo "$(BLUE)Progress: 100%$(RESET)"
	@printf "$(GREEN)Compilation complete!$(RESET)\n"
	@printf "\n$(COL1) ██████╗██╗  ██╗███████╗ ██████╗██╗  ██╗███████╗██████╗ \n"
	@printf "$(COL2)██╔════╝██║  ██║██╔════╝██╔════╝██║ ██╔╝██╔════╝██╔══██╗\n"
	@printf "$(COL3)██║     ███████║█████╗  ██║     █████╔╝ █████╗  ██████╔╝\n"
	@printf "$(COL4)██║     ██╔══██║██╔══╝  ██║     ██╔═██╗ ██╔══╝  ██╔══██╗\n"
	@printf "$(COL5)╚██████╗██║  ██║███████╗╚██████╗██║  ██╗███████╗██║  ██║\n"
	@printf "$(COL6) ╚═════╝╚═╝  ╚═╝╚══════╝ ╚═════╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝$(RESET)\n\n"

clean:
	@make fclean -C ./libft
	@rm -rf $(OBJS_DIR)
	@printf "$(RED)Cleaned object files.$(RESET)\n"

fclean: clean
	@rm -f $(NAME) $(BONUS)
	@printf "$(RED)Removed executables.$(RESET)\n"

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus re_bonus
