/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 16:12:19 by fbenneto          #+#    #+#             */
/*   Updated: 2018/03/28 13:32:03 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

int		ft_fill_ox(char type)
{
	ft_add_char_to_buff('0');
	if (type == 'x' || type == 'X' || type == 'b')
	{
		ft_add_char_to_buff(type);
		return (2);
	}
	return (1);
}

int		ft_get_index(va_list *ap, t_flags *f)
{
	t_buff	*buff;
	int		*i;

	(void)f;
	buff = get_buff();
	i = (int*)va_arg(*ap, int*);
	if (i)
		*i = buff->res + buff->index;
	return (buff->index);
}
