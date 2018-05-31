/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_getopt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 09:04:59 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/05 15:31:56 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int	usage(void)
{
	ft_eprintf("read -r [-p prompt] [-u fd] [-d delim] [name ...]\n\n");
	ft_eprintf("\t-r        : disable the escape char '\\'\n");
	ft_eprintf("\t-p prompt : use `prompt' as a promt\n");
	ft_eprintf("\t-u fd     : use `fd' as input for read\n");
	ft_eprintf("\t-d delim  : delim is used to terminate the"\
	" input line rather than nl\n\n");
	ft_eprintf("\t name ... : the first word is assigned to the first name,\n"\
	"\t\tthe second word to the second name, and so on,\n"\
	"\t\twith leftover words and their intervening separators assigned"\
	" to the last name\n");
	return (1);
}

static int	read_doopt(\
	char ***tav, size_t opt[READ_NB_OPT][2], int c, char *sopt)
{
	char	**av;
	char	*s;
	size_t	i;

	av = *tav;
	if (c == 'h')
		return (usage());
	else if (c == 'r')
		opt[0][0] = 1;
	else
	{
		s = ft_strchr(sopt, c);
		i = s - sopt;
		opt[i][0] = 1;
		av++;
		opt[i][1] = (size_t)*av;
	}
	if (*av)
		av++;
	*tav = av;
	return (0);
}

int			read_getopt(char ***tav, size_t opt[READ_NB_OPT][2], char *sot)
{
	char		**av;
	int			i;

	av = *tav;
	while (*av)
	{
		if (av[0][0] != '-' || (av[0][0] == '-' && (av[0][1] == 0 ||\
		(av[0][1] == '-' && av[0][2] == 0 && av++))))
			break ;
		i = ft_strlen(av[0]);
		if (ft_strchr(sot, av[0][1]) == NULL)
			return (ft_bad_option("read", av[0][1]));
		if (read_doopt(&av, opt, av[0][1], sot))
			return (1);
	}
	*tav = av;
	return (0);
}
