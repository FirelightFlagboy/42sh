/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_history.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 08:58:39 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/28 11:38:27 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		hist_do_opt(int opt, t_sh *sh)
{
	if (opt & 0b10)
		return (hist_read(sh));
	if (opt & 0b100)
		return (hist_write(sh));
	if (opt & 0b1000)
		return (hist_append(sh));
	return (0);
}

int		parse_opt(char **av, char *charset)
{
	int		res;
	char	*s;
	int		i;
	int		p;

	res = 0;
	i = 0;
	while (av[i] && av[i][0] == '-')
	{
		if (av[i][1] == '-' && av[i][2] == 0)
			return (res);
		p = 0;
		while (av[i][++p])
		{
			if ((s = ft_strchr(charset, av[i][p])))
				res |= 1 << (s - charset);
			else
			{
				ft_bad_option("history", av[i][p]);
				return (-1);
			}
		}
		i++;
	}
	return (res);
}

int		built_history(t_sh **tsh)
{
	t_sh	*sh;
	int		opt;

	sh = *tsh;
	if (sh->cmd[1] == NULL)
		return (print_history(tsh));
	if ((opt = parse_opt(sh->cmd + 1, "crwa")) == -1)
		return (1);
	if (opt == 0b110 || opt == 0b1010 || opt == 0b1100)
	{
		ft_eprintf("history : cannot use more than one of -arw\n");
		return (1);
	}
	if (opt & 0b1)
	{
		clean_history(&sh->history->list);
		sh->history->size = 0;
		sh->history->at_index = 0;
	}
	return (hist_do_opt(opt, sh));
}
