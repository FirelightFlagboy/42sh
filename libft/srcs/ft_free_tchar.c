/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 10:52:19 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/20 15:07:13 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_tchar(char **ts)
{
	size_t	i;

	if (ts == NULL)
		return ;
	i = 0;
	while (ts[i])
		free(ts[i++]);
	free(ts);
}
