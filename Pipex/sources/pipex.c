/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afons <afons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 23:24:34 by afons             #+#    #+#             */
/*   Updated: 2026/01/30 02:17:17 by afons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	void	check_env(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			if (env[i][5] == '\0')
			{
				ft_printf("PATH invalid\n");
				exit(EXIT_FAILURE);
			}
			return ;
		}
		i++;
	}
	exit(EXIT_FAILURE);
}

int	main(int ac, char **av, char **env)
{
	t_path_cmd	*path;
	t_fd_file	fd_file;
	t_args		args;

	if (ac != 5)
	{
		ft_printf("Error : put 5 arguments\n");
		exit(EXIT_FAILURE);
	}
	check_env(env);
	fd_file.fd_file1 = open(av[1], O_RDONLY);
	fd_file.fd_file2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd_file.fd_file1 < 0 || fd_file.fd_file2 < 0)
	{
		ft_printf("Error access\n");
		exit(EXIT_FAILURE);
	}
	path = parsing(av);
	args.av = av;
	args.env = env;
	prog(fd_file, path, args);
	free(path->path_cmd1);
	free(path->path_cmd2);
	free(path);
	return (0);
}
