/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_header_fc.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:17:17 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/06 14:27:37 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_HEADER_FC_H
# define FT_PRINTF_HEADER_FC_H

# include <stdarg.h>
# include <stdint.h>
# include "ft_printf_typedef.h"

/*
** Decimal conv
*/
int		ft_call_fillnbr(va_list *ap, t_flags *f);
/*
** Unsigned conv
*/
int		ft_call_fillunbr(va_list *ap, t_flags *f);
/*
** Hexadecimal conv
*/
int		ft_call_fillhex(va_list *ap, t_flags *f);
int		ft_call_filladr(va_list *ap, t_flags *f);
/*
** Octal conv
*/
int		ft_call_filloctal(va_list *ap, t_flags *f);
/*
** Binary conv
*/
int		ft_call_fillbin(va_list *ap, t_flags *f);
/*
** Char conv
*/
int		ft_call_fillchar(va_list *ap, t_flags *f);
int		ft_call_fill_longchar(va_list *ap, t_flags *f);
/*
** String conv
*/
int		ft_call_fillstr(va_list *ap, t_flags *f);
int		ft_call_fill_longstr(va_list *ap, t_flags *f);
/*
** %n
*/
int		ft_get_index(va_list *ap, t_flags *f);
/*
** Float
*/
int		ft_call_fillfloat(va_list *ap, t_flags *f);
/*
** Other
*/
int		ft_putgen_type(va_list *ap, t_flags *f);
int		ft_call_fillcolor(va_list *ap, t_flags *f);
#endif
