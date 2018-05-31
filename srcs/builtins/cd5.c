/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 15:58:59 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/25 09:26:39 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_end_slash(char const *s)
{
	char const *t;

	if (s == NULL)
		return (0);
	t = s;
	while (*s)
		s++;
	if (t != s && *(s - 1) == '/')
		return (1);
	return (0);
}

void	ft_trim_backslash(char *s)
{
	char	*t;

	if (s == NULL)
		return ;
	t = s;
	while (*s)
		s++;
	if (t != s && *(s - 1) == '/')
	{
		s--;
		while (s > t && *s == '/')
		{
			*s = 0;
			s--;
		}
	}
}

size_t	ft_str_count_c(char const *s, int c)
{
	size_t	n;

	if (s == NULL)
		return (0);
	n = 0;
	while (*s)
	{
		if (*s == c)
			n++;
		s++;
	}
	return (n);
}

char	*ft_check_cdpath(char *path, char *file, t_sh **sh)
{
	char	*t;
	t_stat	st;

	if (path[0] != '/')
	{
		if (!(t = get_env_val(sh, "PWD")))
			return (NULL);
		ft_asprintf(&t, "%s/%s/%s", t, path, file);
	}
	else
		ft_asprintf(&t, "%s/%s", path, file);
	if (t == NULL)
		return (NULL);
	if (access(t, F_OK | X_OK))
	{
		free(t);
		return (NULL);
	}
	if (stat(t, &st) || !(S_ISDIR(st.st_mode)))
	{
		free(t);
		return (NULL);
	}
	return (t);
}

int		look_trough_cd_path(t_sh **sh, char *path, struct stat *st, int opt)
{
	char	*cdpath;
	char	**path_to;
	char	*save;
	int		i;

	if (ft_strchr(path, '/') || !(cdpath = get_env_val(sh, "CDPATH")))
		return (handle_errors(sh, path, st));
	if (!(path_to = ft_strsplit(cdpath, ':')))
		return (handle_errors(sh, path, st));
	i = 0;
	save = path;
	while (path_to[i])
	{
		if ((path = ft_check_cdpath(path_to[i++], save, sh)))
		{
			ft_printf("goto : %s\n", path);
			ft_free_tchar(path_to);
			start_moving(sh, path, st, opt);
			free(path);
			return (0);
		}
	}
	ft_free_tchar(path_to);
	stat(save, st);
	return (handle_errors(sh, save, st));
}
