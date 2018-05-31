/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 09:15:33 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/08 09:28:12 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_print_argv(char **argv)
{
	int		i;
	char	*s;

	if (argv == NULL)
		return ;
	i = -1;
	ft_eprintf("=========== argv ============\n\n");
	if (argv && *argv)
	{
		ft_eprintf("    %s\n", argv[0]);
		argv++;
		while (*argv)
		{
			if (*(argv + 1))
				s = "├";
			else
				s = "└";
			ft_eprintf("    %s── %s\n", s, *argv++);
		}
	}
	ft_eprintf("\n=========== argv ============\n\n");
}
