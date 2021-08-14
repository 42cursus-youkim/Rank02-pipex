/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 10:42:30 by youkim            #+#    #+#             */
/*   Updated: 2021/08/14 13:28:19 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	st_digitlen(long long n, int base)
{
	size_t	len;

	len = 0;
	if (!n || ft_lsign(n) == -1)
		len++;
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

/*
** note: does not abs input like original libft;
** instead it would print minus sign as well.
** abs before input if you'd care.
*/
char	*ft_itoa_base(long long n, char *baseset)
{
	int		len;
	int		sign;
	char	*str;
	int		baselen;

	baselen = ft_strlen(baseset);
	len = st_digitlen(n, baselen);
	str = malloc((len + 1) * sizeof(char));
	sign = ft_lsign(n);
	if (!str)
		return (0);
	str[len] = 0;
	while (--len >= 0)
	{
		str[len] = baseset[ft_labs(n % baselen)];
		n = ft_labs(n / baselen);
	}
	if (sign == -1)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	return (ft_itoa_base(n, "0123456789"));
}
