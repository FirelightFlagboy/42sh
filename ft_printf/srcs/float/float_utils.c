/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 15:19:54 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/06 15:57:21 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_header.h"
#include "ft_float.h"

double		ft_modf(double value, double *iptr)
{
	double absvalue;

	if ((absvalue = (value >= 0.0) ? value : -value) >= MAXPOWTWO)
		*iptr = value;
	else
	{
		*iptr = absvalue + MAXPOWTWO;
		*iptr -= MAXPOWTWO;
		while (*iptr > absvalue)
			*iptr -= 1.0;
		if (value < 0.0)
			*iptr = -*iptr;
	}
	return (value - *iptr);
}

double		ft_pow(double d, int p)
{
	double r;

	r = 1;
	while (p)
	{
		r *= d;
		p--;
	}
	return (r);
}

int			ft_len_double(double r, double v, int pre)
{
	int		l;
	int		i;

	l = 0;
	i = 0;
	v = v * ft_pow(10, pre);
	while (v > ft_pow(10, i) || i < pre)
	{
		l++;
		i++;
	}
	if (pre > 0)
		l++;
	i = 0;
	if (r < ft_pow(10, i))
		l++;
	while (r >= ft_pow(10, i++))
		l++;
	return (l);
}

int			ft_isnan_or_inf(double d, t_flags *f)
{
	if (f->type == 'f')
	{
		if (isnan(d))
			return (ft_add_str_to_buff("nan"));
		if (isinf(d))
		{
			if (d < 0.0)
				return (ft_add_str_to_buff("-inf"));
			return (ft_add_str_to_buff("inf"));
		}
	}
	else
	{
		if (isnan(d))
			return (ft_add_str_to_buff("NAN"));
		if (isinf(d))
		{
			if (d < 0.0)
				return (ft_add_str_to_buff("-INF"));
			return (ft_add_str_to_buff("INF"));
		}
	}
	return (0);
}
