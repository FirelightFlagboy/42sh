/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:32:57 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/28 16:37:57 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char		*completion_buffer(t_c_tab *list, t_sh *sh, char *tmp)
{
	char *start;
	char *end;
	char *newcontent;

	list->content[ft_strlen(list->content) - 1] == '/' ? newcontent =
	ft_strdup(list->content) : (newcontent = ft_strjoin(list->content, " "));
	if (!tmp || tmp[0] == '\0')
	{
		start = ft_strsub(sh->buff, 0, sh->term->tc_in);
		end = ft_strsub(sh->buff, sh->term->tc_in,
				sh->term->tc_len - sh->term->tc_in);
		ft_strdel(&sh->buff);
		sh->buff = ft_str3join(start, newcontent, end);
		ft_strdel(&start);
		ft_strdel(&end);
	}
	else
		ft_strnreplace(&(sh->buff), tmp, newcontent, sh->term->tc_in -
				ft_strlen(tmp));
	ft_strdel(&tmp);
	ft_strdel(&newcontent);
	tmp = ft_strdup(sh->buff);
	ft_bzero(sh->buff, ft_strlen(sh->buff));
	return (tmp);
}

char		*fix_cmdname(char **cmd)
{
	char	*tmp;
	char	*to_find;
	size_t	len;

	len = ft_strlen(*cmd);
	tmp = ft_strrchr(*cmd, '/');
	if (!tmp)
	{
		to_find = ft_strdup(*cmd);
		ft_strdel(cmd);
		*cmd = ft_strdup("");
		return (to_find);
	}
	to_find = ft_strdup(tmp + 2);
	len = len - (ft_strlen(tmp) - 2);
	tmp = ft_strndup(*cmd, len);
	ft_strdel(cmd);
	*cmd = tmp;
	return (to_find);
}

t_c_tab		*get_matching(t_c_tab *list, char *path, char *tofind)
{
	DIR				*dir;
	struct dirent	*dp;

	if (!path || path[0] == '\0')
	{
		if (!(dir = opendir(".")))
			return (NULL);
	}
	else if (!(dir = opendir(path)))
		return (NULL);
	while ((dp = readdir(dir)) != NULL)
		if (dp->d_name[0] != '.')
			if (!compare_tab_str(dp->d_name, tofind, ft_strlen(tofind)))
				list = cmd_option(dp->d_name, list);
	closedir(dir);
	return (list);
}

t_c_tab		*get_matching_binary(t_c_tab *list, char *path, char *tofind)
{
	t_c_tab *tmp;
	t_c_tab *tmpstart;
	char	*temp;

	list = NULL;
	tmp = NULL;
	if (!(tmp = name_fill(tmp, path, tofind)))
		return (NULL);
	tmpstart = tmp;
	while (tmp)
	{
		if (tmp->content[ft_strlen(tmp->content) - 1] == '/')
		{
			temp = ft_strndelat(tmp->content, ft_strlen(tmp->content) - 1, 1);
			ft_strdel(&(tmp->content));
			tmp->content = temp;
		}
		if (ft_strchr(tmp->perm, 'x') || ft_strchr(tmp->perm, 'd'))
			list = cmd_option(tmp->content, list);
		tmp = tmp->next;
	}
	clean_list(tmpstart);
	return (list);
}
