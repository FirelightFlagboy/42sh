/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 22:12:25 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/02 14:08:35 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int				cd_end(int ret[2], char *path[2])
{
	if (ret[1])
	{
		ft_strdel(&path[0]);
		ft_strdel(&path[1]);
	}
	return (ret[0]);
}

int				pre_prep(char *path[2], int ret[2], int p_option)
{
	if (!p_option)
	{
		if (ret[1])
			path[1] = path[0];
		if (!(path[0] = ft_path_normalize(path[0])))
			return (1);
		ret[1] = 1;
	}
	return (0);
}

void			ft_free_strtab(char *npath, char *path, char **p, char *s)
{
	free(npath);
	free(path);
	free(p);
	free(s);
}

void			change_symlink_directory(t_sh **sh, char *path)
{
	char	*tmp_pwd;
	char	*pwd;
	char	*tmp;

	if (!(tmp_pwd = ft_strdup(get_env_val(sh, "PWD"))))
		malloc_error();
	if ((tmp = NULL) == NULL && path[0] != '/')
		ft_asprintf(&pwd, "%s/%s", tmp_pwd, path);
	else
		pwd = ft_strdup(path);
	if (pwd == NULL)
		malloc_error();
	tmp = ft_path_normalize(pwd);
	if (chdir(tmp) == 0)
	{
		(*sh)->ret = 0;
		g_exit = 0;
		do_setenv(sh, "OLDPWD", tmp_pwd);
		do_setenv(sh, "PWD", tmp);
	}
	ft_strdel(&tmp);
	ft_strdel(&pwd);
	ft_strdel(&tmp_pwd);
}
