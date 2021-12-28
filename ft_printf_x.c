/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:30:14 by gsheev            #+#    #+#             */
/*   Updated: 2021/12/27 20:54:27 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_x(unsigned int x, int uppercase)
{
	int	n;

	if (uppercase)
		n = ft_print_nbr_base(x, 16, "0123456789ABCDEF");
	else
		n = ft_print_nbr_base(x, 16, "0123456789abcdef");
	return (n);
}
