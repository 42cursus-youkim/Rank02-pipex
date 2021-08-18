/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:53:58 by youkim            #+#    #+#             */
/*   Updated: 2021/08/18 15:02:37 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
#include <stdio.h>
int	main(int argc, char **argv, char **envp)
{
	// printf(">>>%s<<<\n\n\n",argv[2]);
	// char **s = ft_qsplit(argv[2], ' ');
	// for (int i = 0; s[i]; i++)
	// 	printf("->%s\n", s[i]);
	// char **t = ft_qsplit("awk '{count++} END {print count}'", ' ');
	// for (int i = 0; t[i]; i++)
	// 	printf("->%s\n", t[i]);
	// return (0);
	// execve("/usr/bin/awk", argv, envp);
	ft_pipex(argc, argv, envp);
	return (0);
}
