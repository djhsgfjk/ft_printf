# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2021/12/29 13:18:03 by gsheev            #+#    #+#             #
#   Updated: 202#   Updated: 2021/12/29 15:07:07 by gsheev           ###   ########.fr       #                                                              #
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

NORM = norminette

all: $(NAME)

lib:
	@cd $(LIB_PATH) && $(MAKE)
	@cp $(addprefix $(LIB_PATH), $(LIB_NAME)) $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)
	@test -d $(OBJDIR) || mkdir $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

${NAME}: lib $(addprefix ${OBJDIR},${OBJS})
	@ar -rcs $(NAME) $(addprefix $(OBJDIR),$(OBJS))

clean:
	@${RM} $(addprefix $(OBJDIR),$(OBJS))

fclean:	clean
	$(RM) $(NAME)
	@cd $(LIB_PATH) && $(MAKE) fclean

re:	fclean all

compile:
	@gcc main.c -L. -lftprintf && ./a.out

norm:
	@$(NORM) $(addprefix $(SRCDIR),$(SRCS)) $(HEADER)

libnorm:
	@cd $(LIB_PATH) && $(MAKE) norm

