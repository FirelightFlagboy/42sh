/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_typedef.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 16:19:43 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/06 15:13:50 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TYPEDEF_H
# define FT_PRINTF_TYPEDEF_H

# include "ft_printf_d.h"
# include <string.h>
# include <stdarg.h>

typedef struct	s_ite
{
	size_t		i;
	size_t		nbyte;
	size_t		len;
	size_t		max_len;
	int			res;
	int			index;
}				t_ite;

typedef struct	s_flags
{
	unsigned	flags:10;
	char		type;
	char		len_flags[4];
	int			precision;
	int			buff_size;
}				t_flags;

typedef struct	s_type
{
	char		charset;
	int			(*f)(va_list*, t_flags);
}				t_type;

typedef struct	s_buff
{
	char		buffer[BUFF_SIZE_PRINTF];
	size_t		index;
	size_t		res;
	int			fd;
	size_t		max;
	char		*s;
	void		(*put)(struct s_buff *buff);
}				t_buff;

#endif
