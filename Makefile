# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brickard <brickard@student.21-school.ru    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 23:27:33 by brickard          #+#    #+#              #
#    Updated: 2021/12/20 13:52:08 by brickard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		=	libftprintf.a

SRCS		=	ft_printf.c ft_utils.c ft_process_hex.c

SRCS_B		=	ft_printf_bonus.c ft_utils_bonus.c ft_l_itoa_bonus.c\
				ft_parse_flags_bonus.c ft_process_flags_bonus.c\
				ft_process_int_bonus.c ft_process_str_bonus.c\
				ft_process_type_bonus.c ft_process_uint_bonus.c\

HEAD 		= 	./ft_printf.h
HEAD_B		=	./ft_printf_bonus.h

OBJS 		= 	$(SRCS:%.c=%.o)
OBJS_B		=	$(SRCS_B:%.c=%.o)

CC 			= 	gcc

CFLAGS 		= 	-Wall -Wextra -Werror -I$(HEAD)
CFLAGS_B	= 	-Wall -Wextra -Werror -I$(HEAD_B)

RM 			= 	rm -f

.PHONY: 		all clean fclean re bonus

all:			$(NAME)

$(NAME):		$(OBJS) $(HEAD)
				ar rcs $(NAME) $?

%.o	: 			%.c $(HEAD)
				$(CC) $(CFLAGS) -c $< -o $@

bonus:
			make	OBJS="$(OBJS_B)" HEAD="$(HEAD_B)" CFLAGS="$(CFLAGS_B)" all

clean: 
			$(RM) $(OBJS) $(OBJS_B)

fclean:	clean
			$(RM) $(NAME)

re: fclean all