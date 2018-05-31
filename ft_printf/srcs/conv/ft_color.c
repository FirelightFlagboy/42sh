/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 14:28:21 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/06 15:50:39 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"

int		ft_call_fillcolor(va_list *ap, t_flags *f)
{
	int			index;
	const char	*tab[NB_COLOR + 1] = {
		"\x1b[0m", "\x1b[39m", "\x1b[30m", "\x1b[31m", "\x1b[32m", "\x1b[33m",
		"\x1b[34m", "\x1b[35m", "\x1b[36m", "\x1b[37m", "\x1b[90m", "\x1b[91m",
		"\x1b[92m", "\x1b[93m", "\x1b[94m", "\x1b[95m", "\x1b[96m", "\x1b[97m",
		"\x1b[49m", "\x1b[40m", "\x1b[41m", "\x1b[42m", "\x1b[43m", "\x1b[44m",
		"\x1b[45m", "\x1b[46m", "\x1b[47m", "\x1b[100m", "\x1b[101m",
		"\x1b[102m", "\x1b[103m", "\x1b[104m", "\x1b[105m", "\x1b[106m",
		"\x1b[107m", "\x1b[1m", "\x1b[2m", "\x1b[4m", "\x1b[5m", "\x1b[7m",
		"\x1b[8m"
	};

	(void)f;
	index = (int)va_arg(*ap, int);
	if (index < 0 || index > NB_COLOR)
		return (0);
	ft_add_str_to_buff(tab[index]);
	return (0);
}
