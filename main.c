/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:53:58 by youkim            #+#    #+#             */
/*   Updated: 2021/08/12 12:47:10 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int	main(int argc, char **argv, char **envp)
{
//	for (int i = 0; i < argc; i++)
//		printf("arg %d: %s\n", i, argv[i]);
	ft_pipex(argc, argv, envp);

	return (0);
}
