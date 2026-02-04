/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afons <afons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 23:44:28 by afons             #+#    #+#             */
/*   Updated: 2026/01/30 22:04:27 by afons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_cmd(t_path_cmd *path, char *path_cmd)
{
	if (access(path_cmd, F_OK) < 0)
	{
		perror("Command");
		free(path->path_cmd1);
		if (path->path_cmd2)
			free(path->path_cmd2);
		free(path);
		exit(errno);
	}
}

t_path_cmd	*parsing(char **av)
{
	t_path_cmd	*path;
	char		**arg;

	path = ft_calloc(sizeof(t_path_cmd), 1);
	if (!path)
		exit(EXIT_FAILURE);
	arg = ft_split(av[2], ' ');
	if (!arg)
		exit(EXIT_FAILURE);
	path->path_cmd1 = ft_strjoin("/usr/bin/", arg[0]);
	ft_free(arg);
	if (!path->path_cmd1)
		exit(EXIT_FAILURE);
	check_cmd(path, path->path_cmd1);
	arg = ft_split(av[3], ' ');
	if (!arg)
		exit(EXIT_FAILURE);
	path->path_cmd2 = ft_strjoin("/usr/bin/", arg[0]);
	ft_free(arg);
	if (!path->path_cmd2)
		exit(EXIT_FAILURE);
	check_cmd(path, path->path_cmd2);
	return (path);
}
