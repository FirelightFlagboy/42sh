/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:12:06 by anonymous          #+#    #+#             */
/*   Updated: 2018/04/20 15:46:33 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		join_back(char ***split_tab, char **new, int *size, int *i)
{
	char *tmp;

	tmp = NULL;
	*i += 2;
	while (*size != 1)
	{
		if (*split_tab[*i])
		{
			tmp = *new;
			*new = ft_str3join(*new, "/", *split_tab[*i]);
			ft_strdel(&tmp);
		}
		(*i)++;
		(*size)--;
	}
}

static int	sub_parser(t_sh **sh, int *p_option, int *capl, int *i)
{
	int		j;

	while ((*sh)->cmd[*i] != 0)
	{
		if ((*sh)->cmd[*i][0] == '-' && (*sh)->cmd[*i][1] != 0)
		{
			j = 1;
			while ((*sh)->cmd[*i][j] != '\0' &&
					((*sh)->cmd[*i][j] == 'P'
					|| (*sh)->cmd[*i][j] == 'L'))
			{
				if ((*sh)->cmd[*i][j] == 'P')
					*p_option = 1;
				else if ((*sh)->cmd[*i][j] == 'L')
					*capl = 1;
				j++;
			}
			if ((*sh)->cmd[*i][j] != '\0')
				return (-1);
		}
		else
			break ;
		(*i)++;
	}
	return (0);
}

int			parse_cd_options(t_sh **sh, int *p_option, char **path)
{
	int		capl;
	int		i;

	capl = 0;
	i = 1;
	if (sub_parser(sh, p_option, &capl, &i) == -1)
	{
		ft_putstr_fd("cd: invalid option\nUsage: cd [-L|-P] [dir]\n", 2);
		return (-1);
	}
	if (*p_option == 1)
		*p_option = (capl == 1) ? 0 : 1;
	if ((*sh)->cmd[i] == 0)
		(*path) = get_env_val(sh, "HOME");
	else
		(*path) = (*sh)->cmd[i];
	if ((*sh)->cmd[i] && (*sh)->cmd[i + 1])
	{
		ft_eprintf("cd : error too much argument\n");
		return (-1);
	}
	return (0);
}
