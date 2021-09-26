/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:53:58 by youkim            #+#    #+#             */
/*   Updated: 2021/09/26 18:19:56 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	main(int argc, char **argv, char **envp)
{
	if (argc < 5)
		ft_error("to use: ./pipex [here_doc] infile cmd1 cmd2 ... outfile");
	ft_pipex(argc, argv, envp);
	return (0);
}
