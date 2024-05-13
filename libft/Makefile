# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlamarch <tlamarch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/11 17:02:06 by tlamarch          #+#    #+#              #
#    Updated: 2024/04/08 16:22:29 by tlamarch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC	= cc
CFLAGS	= -Wall -Wextra -Werror
SRCSPREFIX	= $(addprefix ft_, $(SRC))
SRCS 	= $(addsuffix .c, $(SRCSPREFIX)) ${SRCGNL} $(SRCPRINT)
OBJS	= ${SRCS:.c=.o}
HEADERS = libft.h
SRCPRINT = ft_printf.c ft_printf_hex.c ft_printf_hex2.c ft_printf_treat.c ft_printf_treat2.c ft_printf_treat3.c ft_printf_util.c ft_printf_util2.c
SRCGNL = get_next_line.c get_next_line_utils.c
SRC = atoi bzero calloc isalnum isalpha isascii isdigit isprint itoa memchr memcmp\
memcpy memmove memset putchar_fd putendl_fd putnbr_fd putstr_fd split strchr strdup\
striteri strjoin strlcat strlcpy strlen strmapi strncmp strnstr strrchr strtrim substr\
lstnew lstadd_front lstsize lstlast lstadd_back tolower toupper lstdelone lstclear lstiter lstmap
NAME	= libft.a
RM	= rm -rf

all: ${NAME}

.c.o :
	${CC} -c ${CFLAGS} $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}
	ranlib ${NAME}

clean:
	${RM} ${OBJS} ${OBJBS}

fclean: clean
	${RM} ${NAME}

re : fclean all
