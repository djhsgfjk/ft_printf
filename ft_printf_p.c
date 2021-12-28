/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 19:29:20 by gsheev            #+#    #+#             */
/*   Updated: 2021/12/29 00:24:52 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf_p(unsigned long int numb)
{
	int d;
	int n;

	if (numb == 0)
	{
		n = write(1, "(nil)", 5);
		return (n);
	}
	d = 1;
	n = write(1, "0x", 2);
	if (n >= 0)
	{
		d = ft_print_nbr_base(numb, 16, "0123456789abcdef");
		if (d >= 0)
			n += d;
		else
			n = d;
	}
	return (n);
}