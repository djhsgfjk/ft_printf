/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:00:26 by gsheev            #+#    #+#             */
/*   Updated: 2021/12/27 23:36:23 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_unbrlen(unsigned int numb)
{
	int d;
	int count;

	count = 0;
	d = 1;
	while (numb / d >= 10)
	{
		count++;
		d *= 10;
	}
	return (count);
}

int	ft_printf_u(unsigned int numb)
{
	int		d;
	int		n;
	int		count;
	char	c;

	count = ft_unbrlen(numb);
	d = 10 * count;
	while (d > 0)
	{
		c = '0' + numb / d;
		n = write(1, &c, 1);
		if (n < 0)
			return (n);
		numb -= (numb / d) * d;
		d /= 10;
	}
	return (count);
}
