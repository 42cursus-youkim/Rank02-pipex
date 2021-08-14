/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 11:38:52 by youkim            #+#    #+#             */
/*   Updated: 2021/08/14 11:21:11 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_lmin(long long a, long long b)
{
	if (a < b)
		return (a);
	return (b);
}

long long	ft_lmax(long long a, long long b)
{
	if (a > b)
		return (a);
	return (b);
}

long long	ft_labs(long long n)
{
	if (n >= 0)
		return (n);
	return (-n);
}

int	ft_lsign(long long n)
{
	if (n < 0)
		return (-1);
	return (1);
}
