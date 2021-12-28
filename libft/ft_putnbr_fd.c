/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:03:33 by gsheev            #+#    #+#             */
/*   Updated: 2021/10/25 11:21:19 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		sign;
	char	c;
	int		d;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		c = '-';
		write(fd, &c, 1);
	}
	d = 1;
	while (n / d >= 10 || n / d <= -10)
		d *= 10;
	while (d > 0)
	{
		c = '0' + sign * (n / d);
		write(fd, &c, 1);
		n -= (n / d) * d;
		d /= 10;
	}
}
