/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 19:43:42 by gsheev            #+#    #+#             */
/*   Updated: 2021/12/26 19:33:06 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s(unsigned char *s)
{
	int	len;
	int	n;

	len = ft_strlen((char *)s);
	n = write(1, s, len);
	return (n);
}
