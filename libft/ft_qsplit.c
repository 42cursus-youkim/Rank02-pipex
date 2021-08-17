/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 13:53:13 by youkim            #+#    #+#             */
/*   Updated: 2021/08/17 17:57:04 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	st_lenstr(size_t i, char const *s, char c)
{
	int		l;
	bool	inq;

	l = -1;
	inq = false;
	while (s[i + (++l)])
	{
		if (s[i + l] == '\'')
			inq = !inq;
		if (!inq && s[i + l] == c)
			break ;
	}
	return (l);
}

static int	st_iterate(char const *s, char c)
{
	int		i;
	int		l;
	int	result;

	i = -1;
	result = 0;
	printf("i : l\n");
	while (s[++i] && i < ft_strlen(s))
	{
		l = st_lenstr(i, s, c);
		if (l > 0)
		{
			printf("%02d:%02d\n", i, l);
			i += l;
			result ++;
		}
	}
	printf("%d/%d\n", i, ft_strlen(s));
	return (result);
}

char	**ft_qsplit(char const *s, char c)
{
	int		i;
	int		w;
	int		l;
	int		n;
	char	*temp;
	char	**result;

	if (!s)
		return (0);
	n = st_iterate(s, c);
	result = malloc((n + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	w = 0;
	i = -1;
	while (s[++i])
	{
		l = st_lenstr(i, s, c);
		if (l > 0)
		{
			result[w] = malloc(l + 1);
			// result[w][l] = ;
			i += l;;
			// printf("%02d\n", l);
		}
	}
	result[n] = 0;
	// printf("n:%d\n", st_lenstr(0, s, c));
}

