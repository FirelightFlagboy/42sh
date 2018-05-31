/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_badconv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 13:28:12 by fbenneto          #+#    #+#             */
/*   Updated: 2018/03/28 13:31:38 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

int		ft_putgen_type(va_list *ap, t_flags *f)
{
	(void)ap;
	if (f->flags & HI_BUFF_SIZE && (f->flags & HI_MINUS) == 0)
	{
		if (f->flags & HI_NULL)
			ft_add_nchar_to_buff('0', f->buff_size - 1);
		else
			ft_add_nchar_to_buff(' ', f->buff_size - 1);
	}
	if (f->type)
		ft_add_char_to_buff(f->type);
	if (f->flags & HI_BUFF_SIZE && f->flags & HI_MINUS)
		ft_add_nchar_to_buff(' ', f->buff_size - 1);
	return (1);
}
