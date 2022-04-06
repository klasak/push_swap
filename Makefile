# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: klasak <klasak@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2021/11/15 09:52:41 by klasak        #+#    #+#                  #
#    Updated: 2021/11/15 09:52:41 by klasak        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

HEADER_FILE		= push_swap.h

SRCS			= push_swap.c\
				ft_atoi.c\
				ft_isdigit_or_sign.c\
				ft_sort_3.c\
				ft_sort_5.c\
				ft_input_check.c\
				ft_operations.c\
				ft_operations2.c\
				ft_radix_help.c \
				ft_radix.c

OBJ_FILES		= $(SRCS:.c=.o)

CFLAGS			= -Wall -Werror -Wextra

cc				= gcc

all:			$(NAME)

$(NAME):		$(OBJ_FILES)
				$(cc) $(CFLAGS) -o $(NAME) $(SRCS)

%.o: 	%.c $(HEADER_FILE)
			$(cc) -c $(CFLAGS) -o $@ $<

clean:
			rm -f $(OBJ_FILES)

fclean:	clean
			rm -f $(NAME)

re:			fclean all

.PHONY:			all clean fclean re %.o