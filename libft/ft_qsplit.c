/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 13:53:13 by youkim            #+#    #+#             */
/*   Updated: 2021/08/17 09:10:01 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#define FLAG 	flag & INQ ? '"':'.',\
	flag & INW ? 'w':'.',\
	flag & FW  ? 'f':'.'
#define LOG printf("%02d:%c %c%c%c (x%d)\n",\
	(int)i, s[i], FLAG, (int)result);
#define LOG2 printf("%02d:%02d:%c %c%c%c\n",\
	(int)i, l, s[i + l], FLAG);
// #define LOG printf("%02d:%c %c%c%c (x%d)\n",\
// 	(int)i, s[i], inq ? '"' : '.', inw ? 'w' : '.', fw ? 'f' : '.', (int)num);
	// (int)i, s[i], inq ? '"' : '.', inw ? 'w' : '.', (int)num);

static int	st_lenstr(size_t i, char const *s, char c)
{
	int		l;
	char	flag;

	l = -1;
	flag = 0;
	while (s[i + (++l)])
	{
		if (s[i + l] == '\'')
			flag ^= INQ;
		if (!(flag & INQ) && s[i + l] == c)
		{
			printf("result l:%d\n",l);
			return (l);
		}
		LOG2
	}
	return (0);
}

static int	st_strsnum(char const *s, char c)
{
	int		i;
	char	flag;
	size_t	result;

	i = -1;
	flag = FW;
	result = 0;
	while (s[++i])
	{
		if (flag & FW && flag & INW)
		{
			flag &= ~FW;
			result++;
		}
		if (s[i] == '\'')
			flag ^= INQ;
		if (!(flag & INQ) && s[i] == c)
			flag &= ~INW;
		else
			flag |= INW;
		if (!(flag & INW))
			flag |= FW;
		LOG
	}
	return (result);
}



static char	**st_alloc2str(char **str2d, size_t numstrs, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (s[i] && j < numstrs)
	{
		while (s[i] == c)
			i++;
		str2d[j] = malloc(st_lenstr(i, s, c) + 1);
		if (!str2d[j])
			return (ft_purge2str(str2d));
		k = 0;
		while (s[i] && s[i] != c)
		{
			str2d[j][k] = s[i];
			i++;
			k++;
		}
		str2d[j][k] = 0;
		j++;
	}
	str2d[j] = 0;
	return (str2d);
}

char	**ft_qsplit(char const *s, char c)
{
	char	**strarr;
	size_t	n;

	if (!s)
		return (0);
	n = st_strsnum(s, c);

	strarr = malloc((n + 1) * sizeof(char *));
	if (!strarr)
		return (0);
	printf("n:%d\n", st_lenstr(0, s, c));
	// return (st_alloc2str(strarr, n, s, c));
}
