/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 22:01:21 by youkim            #+#    #+#             */
/*   Updated: 2021/08/08 22:01:21 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"
#include <stdio.h>


static void init_info(t_info *info, char **argv)
{

	info->infd = open(argv[1], O_RDONLY);
	if (info->infd == ERROR)
		ft_exit("Failed to open input file");
	info->outfd = open(argv[4], O_WRONLY);
	if (info->outfd == ERROR)
		ft_exit("Failed to open output file");
	if (pipe(info->pipefd) == ERROR)
		ft_exit("Failed to create pipe");
	info->pid = fork();
	if (info->pid == ERROR)
		ft_exit("Failed to fork the progress");
	else if (info->pid == CHILD)
		ft_exit("hi, I'm child");
		// ft_pipeout();
	else
		ft_exit("hi, I'm parent");
		// ft_pipein();

	ft_exit("hello there");
}

void ft_pipex(int argc, char **argv)
{
	t_info info;

	for (int i = 0; i < argc; i++)
		printf("arg %d: %s\n", i, argv[i]);
	if (argc != 5)
		ft_exit("to use: ./pipex inflie cmd1 cmd2 outfile");
	init_info(&info, argv);
}

int	main(int argc, char **argv)
{
	ft_pipex(argc, argv);

	return (0);
}