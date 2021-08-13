/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 19:34:27 by youkim            #+#    #+#             */
/*   Updated: 2021/08/11 19:34:27 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define OK 0
# define ERROR -1
# define STDIN 0
# define STDOUT 1

# define CHILD 0
# define PIPE_READ 0
# define PIPE_WRITE 1

# include <fcntl.h>
# include <stdio.h> // remove
# include <sys/wait.h>
# include "./libft/libft.h"

typedef struct s_info
{
	pid_t	pid;
	int		infd;
	int		outfd;
	char	**argslst[2];
	char	**envp;
} t_info;

/*
** ft_pipex
*/
void ft_pipex(int argc, char **argv, char **envp);
void ft_pipein(t_info *info, int pipefd[2]);
void ft_pipeout(t_info *info, int pipefd[2]);
/*
** pathutils
*/
char **ft_getpath(t_info *info);
void ft_exec(t_info *info, int which);

#endif