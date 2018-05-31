/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:42:46 by anonymous          #+#    #+#             */
/*   Updated: 2018/04/24 16:27:25 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char	*get_git_branch_bis(char *line)
{
	char	**array;
	char	*r;
	int		i;

	i = 0;
	if ((array = ft_strsplit(line, ' ')) == NULL)
		return (ft_strdup("error getting branch"));
	while (array[i] && array[i + 1])
		i++;
	r = ft_strdup(array[i]);
	ft_free_tchar(array);
	return (r);
}

char	*get_git_branch(void)
{
	pid_t		pid;
	int			pfd[2];
	char		line[256];
	const char	*argv[] = {"/usr/bin/git", "status", NULL};

	pipe(pfd);
	if ((pid = fork()) == 0)
	{
		ft_redir_fd(pfd[PP_WRITE], STDOUT_FILENO);
		close(STDERR_FILENO);
		execve(argv[0], (char**)argv, NULL);
		exit(EXIT_FAILURE);
	}
	else if (pid == -1)
		return (ft_strdup("error getting branch"));
	if (waitpid(pid, &pid, 0) == -1)
		return (ft_strdup("error getting branch"));
	close(pfd[PP_WRITE]);
	if (pid != 0 && (close(pfd[PP_READ])) != -2)
		return (NULL);
	line[read(pfd[PP_READ], line, 255)] = 0;
	*(ft_strchr(line, '\n')) = 0;
	close(pfd[PP_READ]);
	return (get_git_branch_bis(line));
}

int		change_to_be_commit(char *branch)
{
	int			pfd[2];
	pid_t		pid;
	int			rt;
	const char	*argv[] = {"/usr/bin/git", "status", "--porcelain", NULL};

	if (!branch)
		return (0);
	pipe(pfd);
	if ((pid = fork()) == 0)
	{
		ft_redir_fd(pfd[PP_WRITE], STDOUT_FILENO);
		execve(argv[0], (char**)argv, NULL);
		exit(31);
	}
	else if (pid == -1)
		return (0);
	waitpid(pid, &pid, 0);
	rt = poll(&(struct pollfd){.fd = pfd[PP_READ], .events = POLLIN}\
	, 1, 0) == 1;
	close(pfd[PP_WRITE]);
	close(pfd[PP_READ]);
	return (rt);
}

char	*ft_get_dir(t_sh *sh)
{
	char	*pwd;
	char	*home;
	char	path[PATH_MAX];
	size_t	l;
	char	*t;

	home = ft_get_val(sh, "HOME");
	getcwd(path, PATH_MAX);
	if (!(pwd = ft_get_val(sh, "PWD")))
		pwd = path;
	if (home)
	{
		l = ft_strlen(home);
		if (ft_strncmp(home, pwd, l) == 0)
			ft_asprintf(&t, "~%s", pwd + l);
		else
			t = ft_strdup(pwd);
	}
	else
		t = ft_strdup(pwd);
	return (t);
}

void	build_prompt(t_sh **sh)
{
	char	*col;
	char	*dir;
	char	*br;
	int		commit;

	col = ((*sh)->ret) ? "\033[31m" : "\033[32m";
	br = get_git_branch();
	commit = change_to_be_commit(br);
	dir = ft_get_dir(*sh);
	ft_dprintf((*sh)->ttfd, "\033[0m"
	"\033[2m-----------------------------------------\033[0m\n");
	if (br)
	{
		if (commit)
			ft_dprintf((*sh)->ttfd, "\033[1m\033[38;5;33m%s\033[38;5;39m"
			"(%s%s\033[0;38;5;215m*\033[1;38;5;39m)\033[0m\n", dir, col, br);
		else
			ft_dprintf((*sh)->ttfd, "\033[1m\033[38;5;33m%s\033[38;5;39m"
			"(%s%s\033[38;5;39m)\033[0m\n", dir, col, br);
	}
	else
		ft_dprintf((*sh)->ttfd,\
		"\033[1m%s >> \033[38;5;33m%s\033[0m\n", col, dir);
	ft_strdel(&dir);
	ft_strdel(&br);
}
