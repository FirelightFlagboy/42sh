/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mange_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:42:41 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/02 14:19:33 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static void	write_buffer(t_sh **sh, char *buffer)
{
	char	*ret;
	char	*ret1;
	int		in;
	int		len;
	char	*b;

	len = ft_strlen(buffer);
	(*sh)->term->tc_len += len;
	(*sh)->term->tc_in += len;
	in = (*sh)->term->tc_in;
	len = (*sh)->term->tc_len;
	b = (*sh)->buff;
	if (!b && ((*sh)->buff = ft_strdup(buffer)))
		return ;
	ret = ((in > 1) ? ft_strndup(b, in - ft_strlen(buffer)) : NULL);
	ret1 = (((len - in) > 0) ? ft_strdup(&b[in - ft_strlen(buffer)]) : NULL);
	(*sh)->buff = ft_str3join(ret, buffer, ret1);
	ft_strdel(&ret);
	ft_strdel(&ret1);
	ft_strdel(&b);
}

int			reset_line(t_sh **sh)
{
	(*sh)->term->tc_in = 0;
	(*sh)->term->tc_len = 0;
	return (0);
}

void		work_buffer(t_sh **sh, char *buffer)
{
	size_t i;

	i = 0;
	if (!buffer\
	|| (*sh)->term->tc_len + ft_strlen(buffer) > (*sh)->term->max_len)
		return ;
	write_buffer(sh, buffer);
	ft_putstr(buffer);
	put_space(sh);
	ft_printbuffer(sh);
}
