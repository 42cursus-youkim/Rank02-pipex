/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipeutil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:22:56 by youkim            #+#    #+#             */
/*   Updated: 2021/08/11 16:53:32 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void init_info(t_info *info, char **argv)
{
	info->infd = open(argv[1], O_RDONLY);
	if (info->infd == ERROR)
		ft_error("opening input file");
	info->outfd = open(argv[4], O_WRONLY);
	if (info->outfd == ERROR)
		ft_error("opening output file");
	if (pipe(info->pipefd) == ERROR)
		ft_error("creating pipe");
	info->pid = fork();
	if (info->pid == ERROR)
		ft_error("forking process");
	info->inargs = ft_split(argv[2], ' ');
	info->outargs = ft_split(argv[3], ' ');
}

void ft_pipein(t_info *info)
{
	int i;

	// close(info->pipefd[0]);
	if (dup2(info->infd, STDIN) == ERROR)
		ft_error("connecting infile fd with STDIN");
	if (dup2(info->pipefd[1], STDOUT) == ERROR)
		ft_error("connecting pipe write END with STDOUT");
	i = -1;
	while(info->inargs[++i])
		printf("> %s\n", info->inargs[i]);
	ft_error("this is pipein");
}

void ft_pipeout(t_info *info)
{
	// close(info->pipefd[1]);
	// dup2(info->pipefd[0], STDIN)
	ft_error("this is pipeout");
}

void ft_exec(t_info *info)
{
	int i;

	i = 0;

}