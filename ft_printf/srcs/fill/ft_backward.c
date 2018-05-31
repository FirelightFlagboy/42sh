/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_backward.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 15:55:09 by fbenneto          #+#    #+#             */
/*   Updated: 2018/03/28 13:33:00 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

int		ft_fillbackward(t_flags *f, char neg, int len)
{
	int	l;

	if ((neg || ((f->flags & (HI_ADD | HI_ESCAPE)) && !neg)))
		f->buff_size--;
	if (f->buff_size < len)
		return (0);
	l = f->buff_size - len;
	ft_add_nchar_to_buff(' ', l);
	return (l);
}
