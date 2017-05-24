# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbauer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/21 18:44:49 by bbauer            #+#    #+#              #
#    Updated: 2017/05/23 22:32:01 by bbauer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/ft_printf.a
CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS =  -fsanitize=address -g
LEAKCHECKFLAGS = -g
SRCF = arg_string_splitter.c \
		basic_operations.c \
		build_instructions.c \
		calculate_possible_moves.c \
		create_b_value_array.c \
		debug_log_operations.c \
		debug_print_stacks.c \
		duplicate_input_check.c \
		find_best_candidate.c \
		ops_push.c \
		ops_rev_rotate.c \
		ops_rotate.c \
		ops_swap.c \
		print_output.c \
		read_input.c \
		rotate_largest_to_top.c \
		sort_stacks.c \
		stack_tools.c \

CMAINSRC = checker_main.c
PSMAINSRC = push_swap_main.c

SRC = $(addprefix $(SRCDIR),$(SRCF))
OBJ = $(addprefix $(OBJDIR),$(SRCF:.c=.o))

CMAIN =$(addprefix $(SRCDIR),$(CMAINSRC))
COBJ = $(addprefix $(OBJDIR),$(CMAINSRC:.c=.o))

PSMAIN =$(addprefix $(SRCDIR),$(PSMAINSRC))
PSOBJ = $(addprefix $(OBJDIR),$(PSMAINSRC:.c=.o))

OBJDIR = ./obj/
SRCDIR = ./src/
LIBDIR = ./libft/
FTPFDIR = ./ft_printf/
INCDIR = ./include/

.PHONY: $(NAME), all, clean, fclean, re, $(LIBFT)

all: $(LIBFT) $(FT_PRINTF) checker $(NAME)

$(NAME): $(LIBFT) $(FT_PRINTF) checker
	@echo "Compiling push_swap"
	@$(CC) $(CFLAGS) -c -I$(INCDIR) $(SRC) $(PSMAIN)
	@mkdir -p $(OBJDIR)
	@mv $(SRCF:.c=.o) $(PSMAINSRC:.c=.o) $(OBJDIR)
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR) $(OBJ) $(PSOBJ) $(LIBFT) $(FT_PRINTF) -o $@
	@echo "push_swap: SUCCESS!"

checker: $(LIBFT) $(FT_PRINTF)
	@echo "Compiling the checker"
	@$(CC) $(CFLAGS) -c -I$(INCDIR) $(SRC) $(CMAIN)
	@mkdir -p $(OBJDIR)
	@mv $(SRCF:.c=.o) $(CMAINSRC:.c=.o) $(OBJDIR)
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR) $(OBJ) $(COBJ) $(LIBFT) $(FT_PRINTF) -o $@
	@echo "checker: SUCCESS!"

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
	@rm -f $(NAME) checker
	@make -C $(LIBDIR) fclean
	@make -C $(FTPFDIR) fclean

re: fclean all

debug: $(LIBFT) $(FT_PRINTF)
	@echo "Compiling push_swap with debugging options"
	$(CC) $(CFLAGS) $(SRC) $(CMAINSRC) $(FT_PRINTF) $(LIBFT) -I$(INCDIR) $(DEBUGFLAGS) -o checker_debug
	$(CC) $(CFLAGS) $(SRC) $(PSMAINSRC) $(FT_PRINTF) $(LIBFT) -I$(INCDIR) $(DEBUGFLAGS) -o push_swap_debug

leakcheck: $(LIBFT) $(FT_PRINTF)
	@echo "Compiling push_swap for leak checks with valgrind"
	$(CC) $(CFLAGS) $(SRC) $(CMAINSRC) $(FT_PRINTF) $(LIBFT) -I$(INCDIR) $(LEAKCHECKFLAGS) -o checker_leakcheck
	$(CC) $(CFLAGS) $(SRC) $(PSMAINSRC) $(FT_PRINTF) $(LIBFT) -I$(INCDIR) $(LEAKCHECKFLAGS) -o push_swap_leakcheck
