/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 15:25:45 by gsheev            #+#    #+#             */
/*   Updated: 2021/12/27 23:38:54 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_format(va_list *argptr, char type)
{
	int	n;

	n = -1;
	if (type == 'c')
		n = ft_printf_c(va_arg(*argptr, int));
	else if (type == 's')
		n = ft_printf_s(va_arg(*argptr, unsigned char *));
	else if (type == 'd' || type == 'i')
		n = ft_printf_i(va_arg(*argptr, int));
	else if (type == 'u')
		n = ft_printf_u(va_arg(*argptr, unsigned int));
	else if (type == 'p')
		n = ft_printf_p(va_arg(*argptr, unsigned long int));
	else if (type == 'x')
		n = ft_printf_x(va_arg(*argptr, unsigned int), 0);
	else if (type == 'X')
		n = ft_printf_x(va_arg(*argptr, unsigned int), 1);
	else if (type == '%')
		n = write(1, "%", 1);
	return (n);
}

int	ft_printf(const char *format, ...)
{
	va_list	argptr;
	int		n;
	int		count;

	va_start(argptr, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			n = ft_printf_format(&argptr, *format);
		}
		else
			n = write(1, format, 1);
		if (n < 0)
		{
			count = n;
			break ;
		}
		count += n;
		format++;
	}
	va_end(argptr);
	return (count);
}
