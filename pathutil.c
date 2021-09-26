/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathutil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youkim <youkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:17:57 by youkim            #+#    #+#             */
/*   Updated: 2021/09/26 19:08:43 by youkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

char	**ft_getpath(char **envp)
{
	int		i;

	i = -1;
	while (envp[++i])
		if (ft_strncmp(envp[i], "PATH", 4) == 0)
			return (ft_split(envp[i] + 5, ':'));
	ft_error("PATH not found in envp");
	return (NULL);
}

static void	ft_exec_path(char **cmds, char **envp)
{
	int		i;
	char	*temp;
	char	*path;
	char	**paths;

	i = -1;
	paths = ft_getpath(envp);
	while (paths[++i])
	{
		temp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(temp, cmds[0]);
		execve(path, cmds, envp);
		free(path);
		free(temp);
	}
	ft_purge2str(cmds);
	ft_purge2str(paths);
	ft_error("could not find any matching path for command");
}

void	ft_exec(char *cmd, char **envp)
{
	char	**cmds;

	cmds = ft_qsplit(cmd, ' ');
	if (cmds[0][0] != '/')
		ft_exec_path(cmds, envp);
	if (execve(cmds[0], cmds, envp) == ERROR)
		ft_error("invalid path to command");
	free(cmds);
}
