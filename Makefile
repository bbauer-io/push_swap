# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbauer <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/21 18:44:49 by bbauer            #+#    #+#              #
#    Updated: 2017/04/27 18:17:15 by bbauer           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
LIBFT = ./src/libft/libft.a
CFLAGS = -Wall -Wextra -Werror
DEBUGFLAGS =  -fsanitize=address -g -o push_swap_debug
LEAKCHECKFLAGS = -g -o push_swap_leakcheck
SRCF = push_swap.c \
	   read_input.c \

SRC = $(addprefix $(SRCDIR),$(SRCF))
OBJ = $(addprefix $(OBJDIR),$(SRCF:.c=.o))

OBJDIR = ./obj/
SRCDIR = ./src/
LIBDIR = ./src/libft/
INCDIR = ./include/

.PHONY: $(NAME), all, clean, fclean, re, $(LIBFT)

all: $(LIBFT) $(NAME)

$(NAME): $(LIBFT)
	@echo "Compiling push_swap"
	@$(CC) $(CFLAGS) -c -I$(INCDIR) $(SRC)
	@mkdir -p $(OBJDIR)
	@mv $(SRCF:.c=.o) $(OBJDIR)
	@$(CC) $(CFLAGS) -I$(INCDIR) -I$(LIBDIR) $(OBJ) $(LIBFT) -o $@
	@echo "push_swap: SUCCESS!"

$(LIBFT):
	@make -C $(LIBDIR) all

clean:
	@echo "Cleaning push_swap"
	@rm -rf $(OBJDIR)
	@rm -rf push_swap_debug
	@rm -rf push_swap_debug.dSYM
	@rm -rf push_swap_leakcheck
	@rm -rf push_swap_leakcheck.dSYM
	@make -C $(LIBDIR) clean

fclean: clean
	@echo "FCleaning push_swap"
	@rm -rf $(NAME)
	@make -C $(LIBDIR) fclean

re: fclean all

debug: $(LIBFT)
	@echo "Compiling minishel with debugging options"
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -I$(INCDIR) $(DEBUGFLAGS)

leakcheck: $(LIBFT)
	@echo "Compiling for leak checks with valgrind"
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -I$(INCDIR) $(LEAKCHECKFLAGS)
