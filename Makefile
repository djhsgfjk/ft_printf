# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2021/10/28 16:00:01 by gsheev            #+#    #+#             #
#   Updated: 202#   Updated: 2021/12/29 00:13:32 by gsheev           ###   ########.fr       #                                                              #
# ************************************************************************** #

SRCS = ft_print_nbr_base.c ft_printf_c.c ft_printf_p.c ft_printf_u.c ft_printf.c ft_printf_i.c ft_printf_s.c ft_printf_x.c 

SRCDIR = ./

OBJS = ${SRCS:.c=.o} 

OBJDIR = ${SRCDIR}

HEADER = ft_printf.h

NAME = libftprintf.a

LIB_PATH = ./libft/

LIB_NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all: lib $(NAME)

lib:
	@cd $(LIB_PATH) && $(MAKE)
	@cp $(addprefix $(LIB_PATH), $(LIB_NAME)) $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)
	@test -d $(OBJDIR) || mkdir $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}: $(addprefix ${OBJDIR},${OBJS})
	@ar rs $(NAME) $?

clean:
	${RM} $(addprefix $(OBJDIR),$(OBJS))

fclean:	clean
	$(RM) $(NAME)
#	@cd $(LIB_PATH) && $(MAKE) fclean

re:	fclean all

compile:
	gcc main.c -L. -lftprintf && ./a.out
