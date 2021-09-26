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

int	openf(char *name, t_enum mode)
{
	int	fd;

	if (mode == INPUT)
	{
		ft_chkasn(access(name, F_OK), "input file does not exsist");
		fd = open(name, O_RDONLY);
	}
	else
		fd = open(name, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	return (ft_chkasn(fd, "while opening file"));
}

void	redirect(char *cmd, char **envp)
{
	pid_t	pid;
	int		pipefd[2];

	ft_chkasn(pipe(pipefd), "while creating pipe");
	pid = fork();
	if (pid == CHILD)
	{
		close(pipefd[PREAD]);
		dup2(pipefd[PWRITE], STDOUT_FILENO);
		ft_exec(cmd, envp);
	}
	else if (pid > CHILD)
	{
		close(pipefd[PWRITE]);
		dup2(pipefd[PREAD], STDIN_FILENO);
		waitpid(pid, NULL, WNOHANG);
	}
	else
		ft_error("while forking process");
}

void	ft_pipex_hd(int argc, char **argv, char **envp)
{
	return ;
	// char	*here_doc;

	// while()
}

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
