/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 12:37:05 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/28 12:50:50 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** char	*ft_str_repeat(const char *s, size_t n)
**
** DESCRIPTION
**	Returns input repeated multiplier times.
** Param. #1 - const char s
**	The string to be repeated.
** Param. #2 - size_t n
**	Number of time the input string should be repeated.
**	n has to be greater than or equal to 0.
**	If the multiplier is set to 0, the function will return an empty string.
** RETURN
**	Returns the repeated string.
** EXAMPLES
**	The following sets `newstr' to ``-=-=-=-=-=-=-=-=-=-=''
**		char *newstr = ft_str_repeat("-=", 10);
*/

void	ft_str_replace(char **str, char *old, char *new, int only_one)
{
	int		i;
	int		old_len;
	int		str_len;
	char	*p2;
	char	*tmp;

	i = -1;
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
			if (only_one)
				break ;
			else
				continue ;
		}
}
