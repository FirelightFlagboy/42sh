/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:32:51 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/01 18:19:06 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	ft_dup_content(t_c_tab *tmp)
{
	tmp->name = ft_strdup(tmp->content);
	if (tmp->name == NULL || ft_strcmp(tmp->name, tmp->content) != 0)
		malloc_error();
}

static void	ft_replace_tmp(t_c_tab *tmp, char *cmd)
{
	if (ft_strrchr(cmd, '/'))
		ft_str_replace(&(tmp->name), cmd, "", 1);
	if (tmp->name == NULL)
		malloc_error();
}

t_c_tab		*tab_name(t_c_tab *list, char *cmd)
{
	t_c_tab *tmp;
	char	*tmp_str;

	tmp = list;
	while (tmp)
	{
		tmp_str = tmp->name;
		ft_dup_content(tmp);
		ft_strdel(&tmp_str);
		ft_replace_tmp(tmp, cmd);
		if (tmp->name[ft_strlen(tmp->name) - 1] == '/')
		{
			tmp_str = tmp->name;
			tmp->name = ft_strndelat(tmp->name, ft_strlen(tmp->name) - 1, 1);
			ft_strdel(&tmp_str);
		}
		if (!tmp->perm)
			get_info(tmp);
		if (!cmd)
			return (list);
		tmp = tmp->next;
	}
	return (list);
}
