/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_global.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/24 09:15:37 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/06 15:05:14 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_GLOBAL_H
# define FT_PRINTF_GLOBAL_H

# include <stdlib.h>
# include "ft_printf_header_fc.h"
# include "ft_printf_typedef.h"

/*
** the first fc ptr represent the conv 'x' (120) b:10
** and the last fc ptr represent the conv '@' (64) b:10
** the formula for the hasing to operate is :
** hash = 120 - value_of_char_conv
** if hash > 120 or hash < 0 the conv should be stop
*/

# ifndef PRINTF_SIZE_HASH
#  define PRINTF_SIZE_HASH 57
# endif

int	(*const g_conv[57])(va_list*, t_flags*) =
{
	ft_call_fillhex,
	ft_putgen_type,
	ft_putgen_type,
	ft_call_fillunbr,
	ft_putgen_type,
	ft_call_fillstr,
	ft_putgen_type,
	ft_putgen_type,
	ft_call_filladr,
	ft_call_filloctal,
	ft_get_index,
	ft_putgen_type,
	ft_putgen_type,
	ft_putgen_type,
	ft_putgen_type,
	ft_call_fillnbr,
	ft_putgen_type,
	ft_putgen_type,
	ft_call_fillfloat,
	ft_putgen_type,
	ft_call_fillnbr,
	ft_call_fillchar,
	ft_call_fillbin,
	ft_putgen_type,
	ft_putgen_type,
	ft_putgen_type,
	ft_putgen_type,
	ft_putgen_type,
	ft_putgen_type,
	ft_putgen_type,
	ft_putgen_type,
	ft_putgen_type,
	ft_call_fillhex,
	ft_putgen_type,
	ft_putgen_type,
	ft_call_fillunbr,
	ft_putgen_type,
	ft_call_fill_longstr,
	ft_putgen_type,
	ft_putgen_type,
	ft_putgen_type,
	ft_call_filloctal,
	ft_putgen_type,
	ft_putgen_type,
	ft_putgen_type,
	ft_putgen_type,
	ft_putgen_type,
	ft_putgen_type,
	ft_putgen_type,
	ft_putgen_type,
	ft_call_fillfloat,
	ft_putgen_type,
	ft_call_fillnbr,
	ft_call_fill_longchar,
	ft_call_fillbin,
	ft_putgen_type,
	ft_call_fillcolor,
};
#endif
