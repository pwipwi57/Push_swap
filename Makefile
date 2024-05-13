# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/08 18:10:31 by tlamarch          #+#    #+#              #
#    Updated: 2024/04/11 17:56:04 by tlamarch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc
CFLAGS	= -Wall -Wextra -Werror -g
OBJS	= ${SRCS:.c=.o}
OBJBONUS = ${SRCBONUS:.c=.o}
SRCS	= ft_fr.c ft_fr_2.c list.c parsing.c push_swap.c push.c q_insert.c quicksort.c\
r_rotate.c rotate.c split.c swap.c treatment.c treatment2.c utils.c q_insert_utils.c
SRCBONUS = ft_fr.c ft_fr_2.c list.c parsing.c checker_bonus.c push.c r_rotate.c rotate.c\
split.c swap.c utils.c
SRCLIBFT = atoi bzero calloc isalnum isalpha isascii isdigit isprint itoa memchr memcmp\
memcpy memmove memset putchar_fd putendl_fd putnbr_fd putstr_fd split strchr strdup\
striteri strjoin strlcat strlcpy strlen strmapi strncmp strnstr strrchr strtrim substr\
lstnew lstadd_front lstsize lstlast lstadd_back tolower toupper lstdelone lstclear lstiter lstmap
SRCPRINT = printf printf_hex printf_hex2 printf_treat printf_treat2\
printf_treat3 printf_util printf_util2
SRCGNL = get_next_line get_next_line_utils
NAME = push_swap
NAMEBONUS = checker
LIBFTPREFIX	= $(addprefix libft/ft_, $(SRCLIBFT)) $(addprefix libft/ft_, $(SRCPRINT)) $(addprefix libft/, $(SRCGNL))
LIBFTSRCS = $(addsuffix .c, $(LIBFTPREFIX))
LIBFT_HEADERS = libft/libft.h
RM	= rm -rf

all: ${NAME} 

bonus: ${NAMEBONUS}

.c.o:
	${CC} -c ${CFLAGS} $< -o ${<:.c=.o}

${NAME}: ${OBJS} ${LIBFTSRCS} ${LIBFT_HEADERS} 
	$(MAKE) -C ./libft
	${CC} ${OBJS} libft/libft.a -o ${NAME}

${NAMEBONUS}: ${OBJBONUS} ${LIBFTSRCS} ${LIBFT_HEADERS}
	$(MAKE) -C ./libft
	${CC} ${OBJBONUS} libft/libft.a -o ${NAMEBONUS}

clean:
	${RM} ${OBJS} ${OBJBONUS}
	$(MAKE) clean -C ./libft

fclean: clean
	${RM} ${NAME} ${NAMEBONUS}
	$(MAKE) fclean -C ./libft

re : fclean all

rebonus : fclean bonus

.PHONY: all clean fclean re rebonus bonus