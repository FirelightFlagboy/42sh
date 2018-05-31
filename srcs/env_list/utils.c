/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:42:50 by anonymous          #+#    #+#             */
/*   Updated: 2018/04/24 16:16:21 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Find working dir and set PWD in shell sh
*/

void		set_pwd_env_var(t_sh **sh)
{
	char	*buf;

	if ((buf = (char*)malloc(sizeof(char) * BUFF_SIZE)))
	{
		do_setenv(sh, "PWD", getcwd(buf, BUFF_SIZE));
		free(buf);
	}
}

/*
** return the envornment variable named name in the
** shell sh
*/

char		*get_env_val(t_sh **sh, char *name)
{
	t_envl *start;

	start = (*sh)->env_list;
	while (start)
	{
		if (ft_strcmp(start->name, name) == 0)
			return (start->value);
		start = start->next;
	}
	return (NULL);
}

int			env_lst_size(t_envl *begin_list)
{
	int size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

/*
** add new elem at the beginning of the env list
*/

void		envladd(t_envl **begin_list, t_envl *new)
{
	new->next = *begin_list;
	*begin_list = new;
}

/*
** add new element at the end of env list
*/

int			envladd_back(t_envl **begin_list, t_envl *new)
{
	t_envl *tempenvlist;

	tempenvlist = *begin_list;
	if (!new)
		return (0);
	if (*begin_list)
	{
		while (tempenvlist->next)
			tempenvlist = tempenvlist->next;
		tempenvlist->next = new;
	}
	else
		envladd(begin_list, new);
	return (1);
}
