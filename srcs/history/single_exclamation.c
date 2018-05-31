/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_exclamation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 10:42:30 by anonymous          #+#    #+#             */
/*   Updated: 2018/03/07 16:12:36 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** find the end of the string to expand
** according to type of expansion
*/

static void	single_excl_find_end(char *str, int type, int *till_end)
{
	if (type == 3)
	{
		(*till_end)++;
		while (!(*(str + *till_end) == '\0' || *(str + *till_end) == '?'))
			(*till_end)++;
	}
	else if (type == 2)
		(*till_end) = 1;
	else if (type == 1)
	{
		while (ft_isdigit(*(str + *till_end)) || (*till_end == 0 &&
			*(str + *till_end) == '-' && ft_isdigit(*(str + *till_end + 1))))
			(*till_end)++;
	}
	else
	{
		while (!(*(str + *till_end) == ' ' || *(str + *till_end)) == '\0')
			(*till_end)++;
	}
}

/*
** get history command at specific index
** (type 1: nb)
*/

char		*excl_nb(t_sh **sh, int nb)
{
	t_h_lst	*l;
	int		i;

	if (nb < 0)
		i = (*sh)->history->size + nb;
	else
		i = nb;
	if (!(l = hist_at_index(sh, i)))
		return (NULL);
	return (l->cmd);
}

/*
** go fetch in history command
** or #: command typed so far
*/

char		*get_repl_value(char **cmd, char **arg, int type, int i)
{
	t_sh	*sh;

	sh = gtsh(NULL);
	if (type == 3)
	{
		ft_str_replace(arg, "?", "", 0);
		return (history_search_first_arg_match(&sh, *arg));
	}
	if (type == 2)
		return (ft_strndup(*cmd, i - 1));
	else if (type == 1)
		return (excl_nb(&sh, ft_atoi(*arg)));
	else if (type == 0)
		return (history_search_first_match(&sh, *arg));
	else
		return (NULL);
}

/*
** expand command
*/

int			start_replacing(char **cmd, int *till_end, int *type, int *i)
{
	char	*arg;
	char	*repl;
	char	*old;
	t_sh	*sh;

	sh = gtsh(NULL);
	arg = ft_strndup(*cmd + *i, *till_end);
	repl = NULL;
	if (!(repl = get_repl_value(cmd, &arg, *type, *i)) && no_history_err(arg))
		return (-1);
	if (*type == 3)
		old = ft_strndup(*cmd + *i - 1, 3 + ft_strlen(arg));
	else
		old = ft_strndup(*cmd + *i - 1, 1 + ft_strlen(arg));
	ft_str_replace(cmd, old, repl, 1);
	ft_strdel(&arg);
	ft_strdel(&old);
	(*type == 2) ? ft_strdel(&repl) : (0);
	*i += ft_strlen(repl);
	return (0);
}

/*
** history
** expansion of single exclamation from cmd to s
*/

int			replace_single_exclamation(char **cmd)
{
	int		i;
	int		s;
	int		exptype;

	i = 0;
	while (*((*cmd) + i))
	{
		s = 0;
		while (*((*cmd) + i) && *((*cmd) + i) != '!')
			i++;
		if (!(*((*cmd) + i)))
			break ;
		i++;
		if (*((*cmd) + i) == ' ' || *((*cmd) + i) == '\0')
			return (0);
		exptype = single_excl_type(*cmd + i);
		single_excl_find_end(*cmd + i, exptype, &s);
		if (!s)
			return (0);
		if (start_replacing(cmd, &s, &exptype, &i) == -1)
			return (-1);
	}
	return (0);
}
