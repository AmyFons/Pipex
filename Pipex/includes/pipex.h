/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afons <afons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 23:24:51 by afons             #+#    #+#             */
/*   Updated: 2026/01/30 21:34:06 by afons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <sys/wait.h>
# include "ft_printf.h"

typedef struct s_fd_file
{
	int	fd_file1;
	int	fd_file2;
}	t_fd_file;

typedef struct s_path_cmd
{
	char	*path_cmd1;
	char	*path_cmd2;
}	t_path_cmd;

typedef struct s_args
{
	char	**env;
	char	**av;
}	t_args;

t_path_cmd	*parsing(char **av);
int			main(int ac, char **av, char **env);
char		*ft_strjoin(char const *s1, char const *s2);
void		prog(t_fd_file fd_file, t_path_cmd *path, t_args args);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
void		first_fork(int pipefd[2], t_path_cmd *path,
				t_fd_file fd_file, t_args args);
void		second_fork(int pipefd[2], t_path_cmd *path,
				t_fd_file fd_file, t_args args);
void		free_all(t_path_cmd *path);
void		exec_cmd1(t_path_cmd *path, t_args args);	
void		exec_cmd2(t_path_cmd *path, t_args args);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *s);
void		ft_free(char **str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);

#endif