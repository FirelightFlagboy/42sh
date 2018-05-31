/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:34:31 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/06 15:43:19 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_D_H
# define FT_PRINTF_D_H

/*
** Header that contains all perso define
*/
# ifndef NB_FC
#  define NB_FC 16
# endif

# ifndef NB_COLOR
#  define NB_COLOR 41
# endif

# ifndef BUFF_SIZE_PRINTF
#  define BUFF_SIZE_PRINTF 4096
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 10240
# endif

enum	e_flags_printf
{
	HI_ERROR = 0b1,
	HI_ADD = 0b10,
	HI_HASH = 0b100,
	HI_NULL = 0b1000,
	HI_MINUS = 0b10000,
	HI_ESCAPE = 0b100000,
	HI_PRECISION = 0b1000000,
	HI_BUFF_SIZE = 0b10000000
};

#endif
