/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:53:58 by youkim            #+#    #+#             */
/*   Updated: 2021/09/27 00:51:31 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
		ft_error("to use: ./pipex infile cmd1 cmd2 ...cmdn outfile");
	if (ft_strncmp("here_doc", argv[1], 8) == 0)
	{
		if (argc < 6)
			ft_error("to use: ./pipex here_doc LIMITER cmd cmd1 outfile");
		else
			ft_pipex_hd(argc, argv, envp);
	}
	else
		ft_pipex(argc, argv, envp);
	return (0);
}
