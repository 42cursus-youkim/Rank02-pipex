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

static int	openf(char *name, t_enum mode)
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

static void	redirect(char *cmd, char **envp)
{
	pid_t	pid;
	int		pipefd[2];

	ft_chkasn(pipe(pipefd), "while creating pipe");
	pid = fork();
	if (pid == CHILD)
	{
		close(pipefd[PWRITE]);
		dup2(pipefd[PREAD], STDIN_FILENO);
	}
	else if (pid > CHILD)
	{
		close(pipefd[PREAD]);
		dup2(pipefd[PWRITE], STDOUT_FILENO);
		ft_exec(cmd, envp);
		wait(CHILD);
		// waitpid(0, NULL, 0);
	}
	else
		ft_error("while forking process");
}

void	ft_pipex(int argc, char **argv, char **envp)
{
	int		i;
	t_info	info;

	i = 2;
	if (argc < 5)
		ft_error("to use: ./pipex [here_doc] infile cmd1 cmd2 ... outfile");
	dup2(openf(argv[1], INPUT), STDIN_FILENO);
	dup2(openf(argv[argc - 1], OUTPUT), STDOUT_FILENO);
	while (i < argc - 2)
	{
		fprintf(stderr, "%i:%s\n", i, argv[i]);
		redirect(argv[i++], envp);
	}
	ft_exec(argv[i], envp);
}
