/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 11:46:57 by anonymous          #+#    #+#             */
/*   Updated: 2016/11/11 12:24:58 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
** void ft_putnbr(int n);
**
** NAME
**	 ft_putnbr - write n in stdout.
*/

void	ft_putnbr(int n)
{
	int		n_ascii;

	if (n < 0)
	{
		ft_putchar('-');
		n_ascii = (n % 10) * -1;
		n /= -10;
	}
	else
	{
		n_ascii = n % 10;
		n /= 10;
	}
	if (n)
		ft_putnbr(n);
	ft_putchar(n_ascii + '0');
}
