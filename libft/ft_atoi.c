/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 23:51:16 by gsheev            #+#    #+#             */
/*   Updated: 2021/10/25 14:13:19 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_convert_numb(const char *nptr, int sign)
{
	long int	n;
	int			len;

	n = 0;
	len = 0;
	while (len < 10 && *nptr >= '0' && *nptr <= '9')
	{
		n *= 10;
		len++;
		n += *nptr - '0';
		nptr++;
	}
	if (sign)
		n *= -1;
	if (n > 2147483647 || n < -2147483648)
		return (sign - 1);
	return (n);
}

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	n;

	sign = 0;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n'
		|| *nptr == '\v' || *nptr == '\f' || *nptr == '\r')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign++;
		nptr++;
	}
	n = ft_convert_numb(nptr, sign);
	return (n);
}
