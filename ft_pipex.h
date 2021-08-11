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
# include <sys/types.h>
# include "./libft/libft.h"

typedef struct s_info
{
	int		infd;
	int		outfd;
	int		pipefd[2];
	pid_t	pid;
} t_info;

void ft_pipex(int argc, char **argv);

# define OK 0
# define CHILD 0
# define ERROR -1

#endif