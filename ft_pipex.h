/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 22:08:31 by youkim            #+#    #+#             */
/*   Updated: 2021/08/08 22:08:31 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define OK 0
# define CHILD 0
# define ERROR -1
# define STDIN 0
# define STDOUT 1

# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include "./libft/libft.h"

extern char **environ;

typedef struct s_info
{
	pid_t	pid;
	int		infd;
	int		outfd;
	int		pipefd[2];
	char	(**argslst)[2];
} t_info;


void ft_pipex(int argc, char **argv);
/*
** pipeutils
*/
void init_info(t_info *info, char **argv);
void ft_pipein(t_info *info);
void ft_pipeout(t_info *info);
/*
** pathutils
*/
char **ft_getpaths(void);
void ft_exec(t_info *info, int which);

#endif