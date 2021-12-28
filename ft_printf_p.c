/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:29:20 by gsheev            #+#    #+#             */
/*   Updated: 2021/12/27 23:35:10 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_p(unsigned long int numb)
{
	int count;
	int d;
	int n;

	count = 1;
	d = 1;
	while (numb / d >= 16)
	{
		count++;
		d *= 16;
	}
	n = write(1, "0", (count / 8) + 1 - count);
	if (n >= 0)
	{
		d = ft_print_nbr_base(numb, 16, "0123456789ABCDEF");
		if (d >= 0)
			n += d;
		else
			n = d;
	}
	return (n);
}