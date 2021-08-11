/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathutil.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:17:57 by youkim            #+#    #+#             */
/*   Updated: 2021/08/11 17:59:12 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char **ft_getpaths(void)
{
	int		i;
	char	**paths;

	i = -1;
	while(environ[++i])
	{
		if (ft_strncmp(environ[i], "PATH", 4) == 0)
		{
			return(ft_split(environ[i] + 5, ':'));
		}
	}
	return (NULL);
}

char *getpath()
{

}

void ft_exec(t_info *info, int which)
{
	int i;
	char *temp;
	char *path;
	char **paths;

	if (info->argslst[which][0][0] == '/')
	{
		path = info->argslst[which][0][0];
		if (execve(path, info->argslst[which], environ) == ERROR)
			ft_error("Invalid command address");
		return ;
	}
	i = -1;
	paths = ft_getpaths();
	while(paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp, info->argslst[which][0]);
		execve(path, info->argslst[which], environ);
		free(path);
		free(temp);
	}
	ft_purge2str(paths);
	ft_error("no valid commands found");
}