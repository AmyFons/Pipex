/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afons <afons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 23:09:48 by afons             #+#    #+#             */
/*   Updated: 2026/01/30 01:54:50 by afons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_fork(int pipefd[2], t_path_cmd *path,
	t_fd_file fd_file, t_args args)
{
	close(pipefd[0]);
	dup2(pipefd[1], 1);
	close(pipefd[1]);
	dup2(fd_file.fd_file1, 0);
	close(fd_file.fd_file1);
	close(fd_file.fd_file2);
	exec_cmd1(path, args);
}

void	second_fork(int pipefd[2], t_path_cmd *path,
	t_fd_file fd_file, t_args args)
{
	dup2(pipefd[0], 0);
	close(pipefd[0]);
	dup2(fd_file.fd_file2, 1);
	close(fd_file.fd_file1);
	close(fd_file.fd_file2);
	exec_cmd2(path, args);
}
