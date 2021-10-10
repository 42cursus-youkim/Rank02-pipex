/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:34:22 by youkim            #+#    #+#             */
/*   Updated: 2021/08/11 19:34:22 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	ft_pipex_hd(int argc, char **argv, char **envp)
{
	int		i;
	int		temp;
	char	*limiter;

	limiter = argv[2];
	printf("limiter: %s\n", limiter);
	temp = ft_chkasn(openf("/tmp/.heredoc", TEMP), "while creating temp file");
	fprintf(stderr, "temp: %d\n", temp);
	return ;
	// while()
}

/*
void	ft_pipex(int argc, char **argv, char **envp)
{
	int		i;
	// t_info	info;

	i = 2;
	dup2(openf(argv[1], INPUT), STDIN_FILENO);
	dup2(openf(argv[argc - 1], OUTPUT), STDOUT_FILENO);
	redirect(argv[i++], envp);
	while (i < argc - 2)
		redirect(argv[i++], envp);
	ft_exec(argv[i], envp);
	wait(CHILD);
}
*/