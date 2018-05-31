/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:20:50 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/06 15:58:27 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLOAT_H
# define FT_FLOAT_H

# include <math.h>
# include <float.h>
# include "ft_printf_typedef.h"

# ifndef MAXPOWTWO
#  define MAXPOWTWO	4.503599627370496000E+15
# endif

double	ft_modf(double value, double *iptr);
double	ft_pow(double d, int p);
int		ft_len_double(double r, double v, int pre);
int		ft_fillforward_float(t_flags *f, int neg, int len);
int		ft_isnan_or_inf(double d, t_flags *f);
#endif
