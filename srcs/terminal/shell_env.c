/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 16:08:10 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/03 11:12:33 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** Increment shell level at shell starting
*/

static inline void	incshlvl(t_sh *sh)
{
	char *level;

	level = get_env_val(&sh, "SHLVL");
	if (!level)
		level = ft_strdup("1");
	else
		level = ft_itoa(ft_atoi(level) + 1);
	if (level == NULL)
		malloc_error();
	do_setenv(&sh, "SHLVL", level);
	ft_strdel(&level);
}

/*
** build the environment list
*/

t_envl				*createenv(char **env)
{
	t_envl	*newenv;
	char	*tmp;
	char	*s;

	newenv = NULL;
	if (!env)
		return (NULL);
	s = 0;
	while (*env)
	{
		if (!(s = ft_strdup(*env)))
			malloc_error();
		if ((tmp = ft_strchr(s, '=')))
		{
			*tmp = 0;
			envladd_back(&newenv, envlnew(s, tmp + 1));
		}
		ft_strdel(&s);
		env++;
	}
	return (newenv);
}

/*
** initialize shell->environment & increment shell level
*/

void				initenv(t_sh *sh, char **env)
{
	sh->env = ft_str2dup(env);
	sh->env_list = createenv(sh->env);
	incshlvl(sh);
}
