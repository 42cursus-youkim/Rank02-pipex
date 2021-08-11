/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:47:25 by youkim            #+#    #+#             */
/*   Updated: 2021/08/11 14:18:09 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *s)
{
	return (write(1, s, ft_strlen(s)));
}

void	ft_putstr_fd(int fd, char *s)
{
	if (fd >= 0 && s)
		write(fd, s, ft_strlen(s));
}
