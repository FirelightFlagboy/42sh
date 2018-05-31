/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_placement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 13:30:15 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/18 10:57:57 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	ft_check_placement(void)
{
	char	s[50];
	char	*t;
	int		rt;

	lseek(STDOUT_FILENO, -1, SEEK_END);
	lseek(STDIN_FILENO, -1, SEEK_END);
	ft_printf("\e[6n");
	if ((rt = read(STDIN_FILENO, s, 49)) == -1)
		return ;
	s[rt] = 0;
	if ((t = ft_strchr(s + 2, ';')) == NULL)
		return ;
	if (ft_strncmp(t, ";1R", 3) == 0)
		return ;
	ft_printf("\e[0m\e[7m\e[1m%%\e[0m\n");
}
