/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 11:17:02 by youkim            #+#    #+#             */
/*   Updated: 2021/08/13 17:55:50 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (ft_islower(c))
		return ((c - 'a') + 'A');
	return (c);
}

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		return ((c - 'A') + 'a');
	return (c);
}
