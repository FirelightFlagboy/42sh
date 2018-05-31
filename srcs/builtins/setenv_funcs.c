/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 20:01:04 by eduriez           #+#    #+#             */
/*   Updated: 2018/05/03 12:44:17 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** set name with value in shell sh environment list
*/

void	do_setenv(t_sh **sh, char *name, char *value)
{
	t_envl	*tempenvlist;

	tempenvlist = (*sh)->env_list;
	while (tempenvlist)
	{
		if (ft_strcmp(tempenvlist->name, name) == 0)
		{
			free(tempenvlist->value);
			tempenvlist->value = ft_strdup(value);
			rebuild_str2env(sh);
			return ;
		}
		tempenvlist = tempenvlist->next;
	}
	envladd_back(&(*sh)->env_list, envlnew(name, value));
	rebuild_str2env(sh);
}

int		env_var_error_checking(char *env_str)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	if (!env_str || (!(ft_isalnum(env_str[i]) || env_str[i] == '_')))
	{
		ft_putstr_fd("setenv: bad env var name: ", 2);
		ft_putendl_fd(env_str, 2);
		ret = -1;
	}
	i++;
	while (env_str && env_str[i])
	{
		if (!(ft_isalnum(env_str[i]) || env_str[i] == '_'))
		{
			ft_putstr_fd("setenv: bad env var name: ", 2);
			ft_putendl_fd(env_str, 2);
			ret = -1;
			break ;
		}
		i++;
	}
	g_exit = ret;
	return (ret);
}
