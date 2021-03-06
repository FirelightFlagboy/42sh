/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnreplace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 06:01:04 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/28 12:21:06 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strnreplace(char **str, char *old, char *new, int index)
{
	int		i;
	int		old_len;
	int		str_len;
	char	*p2;
	char	*tmp;

	i = index - 1;
	str_len = ft_strlen(*str);
	old_len = ft_strlen(old);
	while (str_len - ++i >= old_len)
		if (ft_strncmp(*str + i, old, old_len) == 0)
		{
			tmp = *str;
			p2 = *str + i + old_len;
			ft_bzero(*str + i, old_len);
			*str = ft_str3join(*str, new, p2);
			ft_strdel(&tmp);
			str_len = ft_strlen(*str);
			i += ft_strlen(new);
			break ;
		}
}
