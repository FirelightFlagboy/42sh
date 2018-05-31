/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_refresh_hash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 15:36:47 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/04 14:21:09 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hash.h"

static void	ft_hash_add_to(t_hash **hash, char *fp, char *name, uintmax_t index)
{
	t_hash *node;
	t_hash *head;

	if (!(node = ft_hash_create(name, fp)) && ft_warnx_errn("hash", g_errn))
		return ;
	if (hash[index] == NULL && (hash[index] = node))
		return ;
	head = hash[index];
	while (head->next)
		head = head->next;
	head->next = node;
}

static int	ft_work_on_file(char *path)
{
	t_stat st;

	if (stat(path, &st))
		return (0);
	if (!S_ISREG(st.st_mode))
		return (0);
	if (!(st.st_mode & S_IXUSR))
		return (0);
	return (1);
}

static void	ft_build_hash(char *path, t_hash **t)
{
	char		tpath[PATH_MAX];
	t_dirent	*d;
	DIR			*dir;
	size_t		len;

	ft_strcpy(tpath, path);
	len = ft_strlen(tpath);
	if (!(dir = opendir(path)))
		return ;
	while ((d = readdir(dir)))
	{
		if (d->d_name[0] == '.')
			continue;
		ft_strcat(tpath, "/");
		ft_strcat(tpath, d->d_name);
		if (ft_work_on_file(tpath) == 1)
			ft_hash_add_to(t, tpath, d->d_name, ft_hashing(d->d_name));
		tpath[len] = 0;
	}
	closedir(dir);
}

static void	ft_rt_hash(char **epath, t_hash **t)
{
	int i;

	i = -1;
	while (epath[++i])
	{
		if (access(epath[i], F_OK) || access(epath[i], X_OK))
			continue;
		ft_build_hash(epath[i], t);
	}
}

void		ft_refresh_hash(void)
{
	char	*path;
	char	**split;
	t_sh	*sh;

	sh = gtsh(NULL);
	if (no_need_to_refresh(sh))
		return ;
	ft_strdel(&sh->hash_pwd);
	sh->hash_pwd = ft_strdup(ft_get_val(sh, "PATH"));
	sh->hash = get_hash();
	ft_hash_free(sh->hash);
	if (!(path = sh->hash_pwd))
		return ;
	if (!(split = ft_strsplit(path, ':'))\
	&& ft_warnx_errn("hash", (g_errn = ERR_MALLOC)))
		return ;
	ft_rt_hash(split, sh->hash);
	ft_free_tchar(split);
}
