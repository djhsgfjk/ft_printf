/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:31:55 by gsheev            #+#    #+#             */
/*   Updated: 2021/12/29 14:19:44 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nbrlen(int numb)
{
	int	d;

	d = 1;
	while (numb / d >= 10 || numb / d <= -10)
		d *= 10;
	return (d);
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
	int		n;
	int		d;
	int		count;
	char	c;

	d = ft_nbrlen(numb);
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
