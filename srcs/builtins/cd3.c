/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 08:33:51 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/02 14:12:05 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	change_directory(t_sh **sh, char *path)
{
	int		ret;
	char	*rdr;
	char	*tmp_pwd;

	if ((rdr = (char *)malloc(sizeof(char) * BUFF_SIZE)))
	{
		tmp_pwd = ft_strdup(get_env_val(sh, "PWD"));
		if (!(ret = chdir(path)))
		{
			do_setenv(sh, "PWD", getcwd(rdr, BUFF_SIZE));
			do_setenv(sh, "OLDPWD", tmp_pwd);
			(*sh)->ret = ret;
			g_exit = ret;
		}
		ft_strdel(&tmp_pwd);
		ft_strdel(&rdr);
	}
}

int			handle_errors(t_sh **sh, char *path, struct stat *stats)
{
	(void)sh;
	if (access(path, F_OK) != -1)
	{
		if (access(path, R_OK) == -1)
			ft_eprintf("cd : %s : acces denied\n", path);
		else if (!S_ISDIR(stats->st_mode))
			ft_eprintf("cd : %s : not a directory\n", path);
	}
	else
		ft_eprintf("cd : %s : no such file or directory\n", path);
	g_exit = -1;
	return (-1);
}

void		start_moving(t_sh **sh, char *path, struct stat *stats,\
	int p_option)
{
	if (stat(path, stats) == 0 || p_option)
	{
		if (access(path, F_OK | R_OK | X_OK))
		{
			handle_errors(sh, path, stats);
			return ;
		}
		if (p_option == 0)
			return (change_symlink_directory(sh, path));
		else
			return (change_directory(sh, path));
	}
	handle_errors(sh, path, stats);
}

static char	*fix_path_special_cases(t_sh **sh, char *path, int *ma)
{
	char		*oldpwd;
	char		*home;

	oldpwd = NULL;
	home = get_env_val(sh, "HOME");
	if (!path)
	{
		if (!home)
			ft_putendl_fd("cd : HOME not set", 2);
		*ma = 1;
		return (ft_strdup(home));
	}
	else if (ft_strcmp(path, "-") == 0)
	{
		if ((oldpwd = get_env_val(sh, "OLDPWD")))
			ft_eprintf("goto : %s\n", oldpwd);
		else
			ft_eprintf("cd : OLDPWD not set\n");
		*ma = 1;
		return (ft_strdup(oldpwd));
	}
	else
		return (path);
}

int			prep_and_change(t_sh **sh)
{
	struct stat	stats;
	char		*path[2];
	DIR			*opened;
	int			p_option;
	int			ret[2];

	ret[0] = -1;
	ret[1] = 0;
	p_option = 0;
	if (parse_cd_options(sh, &p_option, &path[0]) == -1)
		return (ret[0]);
	if (!(path[0] = fix_path_special_cases(sh, path[0], ret + 1)))
		return (ret[0]);
	path[1] = NULL;
	if (pre_prep(path, ret, p_option))
		malloc_error();
	if ((opened = opendir(path[0])) || p_option)
	{
		start_moving(sh, path[0], &stats, p_option);
		ret[0] = (opened) ? closedir(opened) : (-1);
	}
	else
		ret[0] = look_trough_cd_path(sh, path[0], &stats, p_option);
	return (cd_end(ret, path));
}
