/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:50:07 by youkim            #+#    #+#             */
/*   Updated: 2021/08/11 16:28:19 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_error(char *error)
{
	char *e;
	char *s;

	e = ft_strjoin(error, "\n");
	s = ft_strjoin("Error\nwhile: ", e);
	ft_putstr_fd(2, s);
	if (e)
		free(e);
	if (s)
		free(s);
	exit(0);
}
