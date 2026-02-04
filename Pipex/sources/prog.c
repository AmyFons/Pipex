/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prog.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afons <afons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 03:38:10 by afons             #+#    #+#             */
/*   Updated: 2026/01/30 02:08:28 by afons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd1(t_path_cmd *path, t_args args)
{
	char	**arg_cmd1;

	arg_cmd1 = ft_split(args.av[2], ' ');
	execve(path->path_cmd1, arg_cmd1, args.env);
	perror("Execve");
	exit(errno);
}

void	exec_cmd2(t_path_cmd *path, t_args args)
{
	char	**arg_cmd2;

	arg_cmd2 = ft_split(args.av[3], ' ');
	execve(path->path_cmd2, arg_cmd2, args.env);
	perror("Execve");
	exit(errno);
}

static void	exit_failure(t_path_cmd *path, t_fd_file fd_file)
{
	free_all(path);
	close(fd_file.fd_file1);
	close(fd_file.fd_file2);
	perror("Fork");
	exit(errno);
}

static void	check_pipe(t_path_cmd *path, int pipefd[])
{
	if (pipe(pipefd) < 0)
	{
		free_all(path);
		perror("Pipe");
		exit(errno);
	}
}

void	prog(t_fd_file fd_file, t_path_cmd *path, t_args args)
{
	int		pipefd[2];
	int		pid;
	int		pid2;

	pid = 0;
	check_pipe(path, pipefd);
	if (fd_file.fd_file1 > -1)
	{
		pid = fork();
		if (pid < 0)
			exit_failure(path, fd_file);
		else if (pid == 0)
			first_fork(pipefd, path, fd_file, args);
		close(pipefd[1]);
	}
	pid2 = fork();
	if (pid2 < 0)
		exit_failure(path, fd_file);
	else if (pid2 == 0)
		second_fork(pipefd, path, fd_file, args);
	close(pipefd[0]);
	if (pid)
		waitpid(pid, NULL, 0);
	waitpid(pid2, NULL, 0);
}
