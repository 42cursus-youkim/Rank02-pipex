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

# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include "./libft/libft.h"

typedef struct s_info
{
	int		infd;
	int		outfd;
	int		pipefd[2];
	pid_t	pid;
	char	**inargs;
	char	**outargs;
} t_info;

# define OK 0
# define CHILD 0
# define ERROR -1
# define STDIN 0
# define STDOUT 1

extern char **environ;

void ft_pipex(int argc, char **argv);
/*
** utils
*/
void init_info(t_info *info, char **argv);
void ft_pipein(t_info *info);
void ft_pipeout(t_info *info);

#endif