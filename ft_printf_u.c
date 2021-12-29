/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 20:00:26 by gsheev            #+#    #+#             */
/*   Updated: 2021/12/29 14:30:36 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_unbrlen(unsigned int numb)
{
	unsigned int	d;

	d = 1;
	while (numb / d >= 10)
		d *= 10;
	return (d);
}

int	ft_printf_u(unsigned int numb)
{
	int				n;
	unsigned int	d;
	int				count;
	char			c;

	d = ft_unbrlen(numb);
	count = 0;
	while (d > 0)
	{
		c = '0' + (numb / d);
		n = write(1, &c, 1);
		if (n <= 0)
			return (n);
		count += n;
		numb -= (numb / d) * d;
		d /= 10;
	}
	return (count);
}
