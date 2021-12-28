/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:31:55 by gsheev            #+#    #+#             */
/*   Updated: 2021/12/27 23:58:28 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(int numb)
{
	int d;
	int count;

	count = 0;
	d = 1;
	while (numb / d >= 10 || numb / d <= -10)
	{
		count++;
		d *= 10;
	}
	return (count);
}

static int	ft_nbrsign(int numb)
{
	int	sign;
	int	n;

	sign = 1;
	if (numb < 0)
	{
		sign = -1;
		n = write(1, "-", 1);
		if (n <= 0)
			return (0);
	}
	return (sign);
}

int	ft_printf_i(int numb)
{
	int		sign;
	int		d;
	int		n;
	int		count;
	char	c;

	count = ft_nbrlen(numb);
	d = 10 * count;
	sign = ft_nbrsign(numb);
	if (sign == 0)
		return (-1);
	count = ((-1 * sign) + 1) / 2;
	while (d > 0)
	{
		c = '0' + sign * (numb / d);
		n = write(1, &c, 1);
		if (n <= 0)
			return (n);
		count += n;
		numb -= (numb / d) * d;
		d /= 10;
	}
	return (count);
}
