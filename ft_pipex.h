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

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include "./libft/libft.h"
# include <stdio.h> // REMOVE
typedef enum e_enum
{
	CHILD = 0,
	PREAD = 0,
	PWRITE = 1,
	INPUT = 0,
	OUTPUT = 1,
}	t_enum;

typedef struct s_info
{
	pid_t	pid;
	int		infd;
	int		outfd;
	char	**argslst[2];
	char	**envp;
}	t_info;

/*
** ft_pipex
*/
void	ft_pipex(int argc, char **argv, char **envp);
void	ft_pipex_hd(int argc, char **argv, char **envp);
int		openf(char *name, t_enum mode);
void	redirect(char *cmd, char **envp);
/*
** pathutils
*/
char	**ft_getpath(char **envp);
void	ft_exec(char *cmd, char **envp);

#endif