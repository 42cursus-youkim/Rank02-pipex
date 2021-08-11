/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipeutil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 15:22:56 by youkim            #+#    #+#             */
/*   Updated: 2021/08/11 17:46:01 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void init_info(t_info *info, char **argv)
{
	info->infd = open(argv[1], O_RDONLY);
	if (info->infd == ERROR)
		ft_error("while opening input file");
	info->outfd = open(argv[4], O_WRONLY);
	if (info->outfd == ERROR)
		ft_error("while opening output file");
	if (pipe(info->pipefd) == ERROR)
		ft_error("while creating pipe");
	info->pid = fork();
	if (info->pid == ERROR)
		ft_error("while forking process");
	info->argslst[0] = ft_split(argv[2], ' ');
	info->argslst[1] = ft_split(argv[3], ' ');
}

void ft_pipein(t_info *info)
{

	// close(info->pipefd[0]);
/*
** 	if (dup2(info->infd, STDIN) == ERROR)
** 		ft_error("connecting infile fd with STDIN");
** 	if (dup2(info->pipefd[1], STDOUT) == ERROR)
** 		ft_error("connecting pipe write END with STDOUT");
*/

	ft_exec(info, 0);
	ft_purge2str(info->argslst[0]);
	close(info->infd);
	close(info->pipefd[1]);
	wait(CHILD);
}

void ft_pipeout(t_info *info)
{
	return;
	// close(info->pipefd[1]);
	// dup2(info->pipefd[0], STDIN)
	// ft_error("this is pipeout");
}

