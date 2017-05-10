# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbauer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/21 18:44:49 by bbauer            #+#    #+#              #
#    Updated: 2017/05/09 15:37:22 by bbauer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/ft_printf.a
CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS =  -fsanitize=address -g -o push_swap_debug
LEAKCHECKFLAGS = -g -o push_swap_leakcheck
SRCF = arg_string_splitter.c \
		basic_operations.c \
		build_instructions.c \
		calculate_possible_moves.c \
		crappy_temp_print_stack.c \
		debug_log_operations.c \
		debug_print_stacks.c \
		duplicate_input_check.c \
		find_best_candidate.c \
		ops_push.c \
		ops_rev_rotate.c \
		ops_rotate.c \
		ops_swap.c \
		print_output.c \
		push_swap_main.c \
		read_input.c \
		sort_stacks.c \
		stack_tools.c \

SRC = $(addprefix $(SRCDIR),$(SRCF))
OBJ = $(addprefix $(OBJDIR),$(SRCF:.c=.o))

OBJDIR = ./obj/
SRCDIR = ./src/
LIBDIR = ./libft/
FTPFDIR = ./ft_printf/
INCDIR = ./include/

.PHONY: $(NAME), all, clean, fclean, re, $(LIBFT)

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF)
	@echo "Compiling push_swap"
	@$(CC) $(CFLAGS) -c -I$(INCDIR) $(SRC)
	@mkdir -p $(OBJDIR)
	@mv $(SRCF:.c=.o) $(OBJDIR)
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $@
	@echo "push_swap: SUCCESS!"

$(LIBFT):
	@make -C $(LIBDIR) all

$(FT_PRINTF): $(LIBFT)
	@make -C $(FTPFDIR) all

clean:
	@echo "Cleaning push_swap"
	@rm -rf $(OBJDIR)
	@rm -f push_swap_debug
	@rm -rf push_swap_debug.dSYM
	@rm -f push_swap_leakcheck
	@rm -rf push_swap_leakcheck.dSYM
	@make -C $(LIBDIR) clean
	@make -C $(FTPFDIR) clean

fclean: clean
	@echo "FCleaning push_swap"
	@rm -f $(NAME)
	@make -C $(LIBDIR) fclean
	@make -C $(FTPFDIR) fclean

re: fclean all

debug: $(LIBFT) $(FT_PRINTF)
	@echo "Compiling push_swap with debugging options"
	$(CC) $(CFLAGS) $(SRC) $(FT_PRINTF) $(LIBFT) -I$(INCDIR) $(DEBUGFLAGS)

leakcheck: $(LIBFT) $(FT_PRINTF)
	@echo "Compiling push_swap for leak checks with valgrind"
	$(CC) $(CFLAGS) $(SRC) $(FT_PRINTF) $(LIBFT) -I$(INCDIR) $(LEAKCHECKFLAGS)

