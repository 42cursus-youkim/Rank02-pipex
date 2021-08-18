/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:53:58 by youkim            #+#    #+#             */
/*   Updated: 2021/08/18 20:01:04 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
#include <stdio.h>
int	main(int argc, char **argv, char **envp)
{
	printf("%d", argc);
	ft_pipex(argc, argv, envp);
	return (0);
}
