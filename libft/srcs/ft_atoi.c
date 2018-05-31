/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 22:16:42 by anonymous          #+#    #+#             */
/*   Updated: 2017/01/07 01:47:02 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** int	atoi(const char *str);
**
** NAME
**	ftatoi -- convert ASCII string to integer
** DESCRIPTION
**	The atoi() function converts the initial portion of the string pointed to
**	by str to int representation.
**	Skip white space and pick up leading +/- sign if any.
**	 Compute the cutoff value between legal numbers and illegal numbers.
**	It is equivalent to:
**	(int)strtol(str, (char **)NULL, 10);
*/

int			ft_atoi(const char *str)
{
	int		neg;
	long	nb;

	neg = 0;
	nb = 0;
	while (ft_isspace(*str))
		str++;
	if ((*str == '-' && ++neg) || *str == '+')
		str++;
	while (ft_isdigit(*str))
		nb = nb * 10 + *str++ - '0';
	if (neg)
		nb = -nb;
	return (int)nb;
}
