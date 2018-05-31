/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_argv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 10:33:07 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/02 16:35:58 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	ft_len_argv(t_token *tk, int size)
{
	int		res;
	int		i;

	res = 0;
	i = -1;
	while (++i < size)
	{
		if (tk[i].name == NORMAL_WORD)
			res++;
		else if (tk[i].name == IO_NUMBER)
			i += 2;
		else if (tk[i].family == OP_REDIR)
			i++;
	}
	return (res);
}

int			ft_get_argv(char ***argv, t_token *tk, int size_token)
{
	char	**av;
	int		count;
	int		i;
	int		y;

	count = ft_len_argv(tk, size_token);
	if (!(av = (char**)malloc((count + 1) * sizeof(char*))))
		return (-1);
	i = 0;
	y = 0;
	av[count] = NULL;
	while (i < count)
	{
		if (tk[y].name == NORMAL_WORD)
			av[i++] = ft_get_arg(tk[y]);
		else if (tk[y].family == OP_REDIR)
			y++;
		else if (tk[y].name == IO_NUMBER)
			y += 2;
		y++;
	}
	i = -1;
	*argv = av;
	return (count);
}
