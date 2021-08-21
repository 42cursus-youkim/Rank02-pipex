/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putliteral.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:41:14 by youkim            #+#    #+#             */
/*   Updated: 2021/08/21 15:04:04 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	return (write(1, s, ft_strlen(s)));
}

int	ft_putchar_fd(int fd, char c)
{
	if (fd >= 0 && ft_isascii(c))
		return (write(fd, &c, 1));
	return (ERROR);
}

int	ft_putstr_fd(int fd, char *s)
{
	if (fd >= 0 && s)
		return (write(fd, s, ft_strlen(s)));
	return (ERROR);
}

void	ft_putendl_fd(int fd, char *s)
{
	if (fd >= 0 && s)
	{
		ft_putstr_fd(fd, s);
		ft_putchar_fd(fd, '\n');
	}
}
