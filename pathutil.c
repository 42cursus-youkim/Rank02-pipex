/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathutil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:17:57 by youkim            #+#    #+#             */
/*   Updated: 2021/08/20 16:07:07 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char	**ft_getpath(t_info *info)
{
	int		i;

	i = -1;
	while (info->envp[++i])
		if (ft_strncmp(info->envp[i], "PATH", 4) == 0)
			return (ft_split(info->envp[i] + 5, ':'));
	return (NULL);
}

static void	ft_exec_path(t_info *info, int which)
{
	int		i;
	char	*temp;
	char	*path;
	char	**paths;

	i = -1;
	paths = ft_getpath(info);
	while (paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp, info->argslst[which][0]);
		execve(path, info->argslst[which], info->envp);
		free(path);
		free(temp);
	}
	ft_purge2str(paths);
	ft_purge2str(info->argslst[0]);
	ft_purge2str(info->argslst[1]);
	ft_error("could not find any matching path for command");
}

void	ft_exec(t_info *info, int which)
{
	char	*path;

	if (info->argslst[which][0][0] != '/')
		ft_exec_path(info, which);
	path = info->argslst[which][0];
	if (execve(path, info->argslst[which], info->envp) == ERROR)
		ft_error("invalid path to command");
	return ;
}
