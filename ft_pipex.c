/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 22:01:21 by youkim            #+#    #+#             */
/*   Updated: 2021/08/08 22:01:21 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void ft_pipex(int argc, char **argv)
{
	t_info info;

	for (int i = 0; i < argc; i++)
		printf("arg %d: %s\n", i, argv[i]);
	init_info(&info, argv);
	if (info.pid == CHILD)
		ft_pipeout(&info);
	else
		ft_pipein(&info);
}

int	main(int argc, char **argv)
{
	if (argc != 5)
		ft_error("to use: ./pipex inflie cmd1 cmd2 outfile");
	ft_pipex(argc, argv);

	return (0);
}