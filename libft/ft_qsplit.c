/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 13:53:13 by youkim            #+#    #+#             */
/*   Updated: 2021/08/20 16:09:32 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	st_lenstr(size_t i, char const *s, char c)
{
	int		l;
	bool	inq;
	char	whichq;

	l = -1;
	inq = false;
	whichq = '\'';
	while (s[i + (++l)])
	{
		if (!inq && ft_strchr("'\"", s[i + l]))
			whichq = s[i + l];
		if (s[i + l] == whichq)
			inq = !inq;
		if (!inq && s[i + l] == c)
			break ;
	}
	return (l);
}

static int	st_iterate(char const *s, char c)
{
	int	i;
	int	l;
	int	result;

	i = -1;
	result = 0;
	while (s[++i] && (size_t)i < ft_strlen(s))
	{
		l = st_lenstr(i, s, c);
		if (l > 0)
		{
			i += l;
			result ++;
		}
	}
	return (result);
}

static void	st_removq(char **s)
{
	int	i;

	i = -1;
	while ((*s)[++i])
		if (ft_strchr("'\"", (*s)[i]))
			(*s)[i] = ' ';
}

char	**st_writearr(char const *s, char c, int n, char **result)
{
	int	i;
	int	l;
	int	w;

	w = 0;
	i = -1;
	while (s[++i] && (size_t)i < ft_strlen(s))
	{
		l = st_lenstr(i, s, c);
		if (l > 0)
		{
			result[w] = malloc(l + 1);
			if (!result[w])
				return (ft_purge2str(result));
			ft_strlcpy(result[w], s + i, l + 1);
			st_removq(&result[w++]);
			i += l;
		}
	}
	result[n] = 0;
	return (result);
}

char	**ft_qsplit(char const *s, char c)
{
	int		i;
	int		n;
	char	**result;

	if (!s)
		return (0);
	n = st_iterate(s, c);
	result = malloc((n + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	return (st_writearr(s, c, n, result));
}
