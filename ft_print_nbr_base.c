/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_base.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:07:57 by gsheev            #+#    #+#             */
/*   Updated: 2021/12/27 23:30:19 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_nbr_base(unsigned long int nbr, unsigned long int nb, char *base)
{
	int	n;

	n = 0;
	if (nbr >= nb)
	{
		n = ft_print_nbr_base(nbr / nb, nb, base);
		n += ft_print_nbr_base(nbr % nb, nb, base);
	}
	else
		n = write(1, &(base[nbr]), 1);
	return (n);
}
