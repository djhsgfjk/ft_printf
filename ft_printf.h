/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 15:39:56 by gsheev            #+#    #+#             */
/*   Updated: 2021/12/28 00:01:21 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_printf_c(char c);
int	ft_printf_s(unsigned char *s);
int	ft_printf_i(int numb);
int	ft_printf_u(unsigned int numb);
int ft_print_nbr_base(unsigned int nbr, unsigned int nb, char *base);
int ft_printf_p(unsigned long int p);
int	ft_printf_x(unsigned int x, int uppercase);

#endif
