# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 18:10:31 by tlamarch          #+#    #+#              #
#    Updated: 2024/06/26 16:58:09 by tlamarch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS_NAME = checker
CC = cc

FLAGS = -Wall -Werror -Wextra -g

LIBFT_FLAG = libft/libft.a

SRCS_MDIR = srcs/mandatory/
SRCS_BDIR = srcs/bonus/
OBJS_MDIR = objs/mandatory/
OBJS_BDIR = objs/bonus/

HEADER = $(SRCS_MDIR)push_swap.h
BONUS_HEADER = $(SRCS_BDIR)checker_bonus.h

SRCS = $(SRCS_MDIR)ft_fr_2.c \
		$(SRCS_MDIR)ft_fr.c \
		$(SRCS_MDIR)i_push.c \
		$(SRCS_MDIR)i_rotate.c \
		$(SRCS_MDIR)i_rrotate.c \
		$(SRCS_MDIR)i_swap.c \
		$(SRCS_MDIR)list.c \
		$(SRCS_MDIR)parsing.c \
		$(SRCS_MDIR)push_swap.c \
		$(SRCS_MDIR)q_insert_utils.c \
		$(SRCS_MDIR)q_insert.c \
		$(SRCS_MDIR)quicksort.c \
		$(SRCS_MDIR)split.c \
		$(SRCS_MDIR)treatment.c \
		$(SRCS_MDIR)treatment2.c \
		$(SRCS_MDIR)utils.c \

BONUS_SRCS = $(SRCS_BDIR)ft_fr_2.c \
		$(SRCS_BDIR)ft_fr.c \
		$(SRCS_BDIR)i_push.c \
		$(SRCS_BDIR)i_rotate.c \
		$(SRCS_BDIR)i_rrotate.c \
		$(SRCS_BDIR)i_swap.c \
		$(SRCS_BDIR)list.c \
		$(SRCS_BDIR)parsing.c \
		$(SRCS_BDIR)q_insert_utils.c \
		$(SRCS_BDIR)q_insert.c \
		$(SRCS_BDIR)quicksort.c \
		$(SRCS_BDIR)split.c \
		$(SRCS_BDIR)treatment.c \
		$(SRCS_BDIR)treatment2.c \
		$(SRCS_BDIR)utils.c \
		$(SRCS_BDIR)checker_bonus.c \

OBJS = $(patsubst $(SRCS_MDIR)%.c,$(OBJS_MDIR)%.o,$(SRCS))

BONUS_OBJS = $(patsubst $(SRCS_BDIR)%.c,$(OBJS_BDIR)%.o,$(BONUS_SRCS))

$(OBJS_MDIR)%.o : $(SRCS_MDIR)%.c $(HEADER) | $(OBJS_MDIR)
	$(CC) $(FLAGS) -Ilibft -o $@ -c $<

$(OBJS_BDIR)%.o : $(SRCS_BDIR)%.c $(BONUS_HEADER) | $(OBJS_BDIR)
	$(CC) $(FLAGS) -Ilibft -o $@ -c $<

$(NAME): $(OBJS) $(HEADER)
	make -C libft/
	$(CC) $(FLAGS) -o $@ $(OBJS) $(LIBFT_FLAG)

$(BONUS_NAME): $(BONUS_OBJS) $(BONUS_HEADER)
	make -C libft/
	$(CC) $(FLAGS) -o $@ $(BONUS_OBJS) $(LIBFT_FLAG)

$(OBJS_MDIR) :
	mkdir -p $(OBJS_MDIR)

$(OBJS_BDIR) :
	mkdir -p $(OBJS_BDIR)

all : $(NAME) $(BONUS_NAME)

bonus : $(BONUS_NAME)

clean :
	make -C libft/ clean
	rm -rf $(OBJS_MDIR) $(OBJS_BDIR)

fclean : clean
	make -C libft/ fclean
	rm -f $(NAME) $(BONUS_NAME)
	rm -rf $(OBJS_MDIR) $(OBJS_BDIR)

re : fclean $(OBJS_MDIR) $(NAME)

rebonus : fclean bonus

.PHONY: all clean fclean re rebonus bonus
