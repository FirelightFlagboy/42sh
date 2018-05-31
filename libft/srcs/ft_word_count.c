/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 14:12:42 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/27 16:56:51 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_word_count(char const *s, char c)
{
	int	i;
	int	wc;
	int	found;

	i = 0;
	wc = 0;
	found = 0;
	while (s[i])
	{
		if (s[i] == c)
			found = 0;
		else
		{
			if (found == 0)
				wc++;
			found = 1;
		}
		i++;
	}
	return (wc);
}
