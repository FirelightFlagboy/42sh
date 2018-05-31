/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_workopt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 10:27:07 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/08 10:38:00 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		read_getfd(size_t opt[READ_NB_OPT][2])
{
	int	stdin;

	if (opt[2][0] == 0)
		stdin = 0;
	else
	{
		if (opt[2][1] && ft_isall_num((char*)opt[2][1]))
			stdin = ft_atoi((char*)opt[2][1]);
		else
		{
			if (opt[2][1])
				ft_eprintf("read : %s : invalide file descriptor"\
				" specification\n", opt[2][1]);
			else
				ft_eprintf("read : -u : options requires an argument\n");
			return (-1);
		}
	}
	if (fcntl(stdin, F_GETFD) == -1)
	{
		ft_eprintf("read : %d : invalid file descriptor"\
		" : Bad file descriptor\n", stdin);
		return (-1);
	}
	return (stdin);
}

char	*read_getprompt(size_t opt[READ_NB_OPT][2])
{
	if (opt[1][0] == 0 || opt[1][1] == 0)
		return (NULL);
	return ((char*)opt[1][1]);
}

char	read_getdelim(size_t opt[READ_NB_OPT][2])
{
	if (opt[3][0] == 0)
		return ('\n');
	if (opt[3][1] == 0)
	{
		ft_eprintf("read : -d : option requires an argument\n");
		return (-1);
	}
	return (((char*)opt[3][1])[0]);
}
