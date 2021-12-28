/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsheev <gsheev@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 00:03:44 by gsheev            #+#    #+#             */
/*   Updated: 2021/10/25 12:27:51 by gsheev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static char	**ft_make_free(char **s_arr, int *start, int *len)
{
	int	i;

	i = 0;
	if (s_arr != (void *)0)
	{
		while (s_arr[i] != (void *) 0)
		{
			free(s_arr[i]);
			i++;
		}
		free(s_arr);
	}
	if (start != (void *)0)
		free(start);
	if (len != (void *)0)
		free(len);
	return ((char **)0);
}

static int	ft_words_count(char const *s, char c)
{
	int	i;
	int	count;

	if (s[0] == '\0')
		return (0);
	if (c == '\0')
		return (1);
	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
			if (i == 0 || s[i - 1] == c)
				count++;
		i++;
	}
	return (count);
}

static void	ft_start_and_len(char const *s, char c, int **start, int **len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			(*start)[j] = i;
			(*len)[j] = 0;
			while (s[i] && s[i] != c)
			{
				(*len)[j]++;
				i++;
			}
			j++;
		}
	}
}

static char	**ft_full_array(char const *s, int count, int *start, int *len)
{
	int		i;
	int		j;
	char	**s_arr;

	s_arr = malloc((count + 1) * sizeof(char *));
	if (s_arr == (void *)0)
		return (ft_make_free(s_arr, start, len));
	i = 0;
	while (i < count)
	{
		s_arr[i] = malloc((len[i] + 1) * sizeof(char));
		if (s_arr[i] == (void *)0)
			return (ft_make_free(s_arr, start, len));
		j = 0;
		while (j < len[i])
		{
			s_arr[i][j] = s[start[i] + j];
			j++;
		}
		s_arr[i][j] = '\0';
		i++;
	}
	s_arr[i] = (void *)0;
	(void)ft_make_free((void *)0, start, len);
	return (s_arr);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	int		*start;
	int		*len;

	if (s == (void *)0)
		return ((char **)0);
	count = ft_words_count(s, c);
	start = malloc(count * sizeof(int));
	len = malloc(count * sizeof(int));
	if (start == (void *)0 || len == (void *)0)
		return (ft_make_free((void *)0, start, len));
	ft_start_and_len(s, c, &start, &len);
	return (ft_full_array(s, count, start, len));
}
