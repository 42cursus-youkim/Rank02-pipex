/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:48:31 by youkim            #+#    #+#             */
/*   Updated: 2021/08/17 19:11:35 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrd(const char *s, const char *r)
{
	int		i;
	size_t	j;
	int		torm;
	char	*result;

	i = -1;
	torm = 0;
	while (s[++i])
		if (ft_strchr(r, s[i]))
			torm++;
	result = malloc(ft_strlen(s) - torm + 1);
	if (!result)
		return (NULL);
	result[ft_strlen(s) - torm] = 0;
	i = 0;
	j = 0;
	while (j < ft_strlen(s) - torm)
	{
		if (ft_strchr(r, s[i]))
			i++;
		else
			result[j++] = s[i++];
	}
	return (result);
}
