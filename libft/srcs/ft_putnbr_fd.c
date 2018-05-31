/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:32:23 by anonymous          #+#    #+#             */
/*   Updated: 2016/11/11 12:32:30 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
** void ft_putnbr_fd(int n, int fd);
**
** NAME
**	 ft_putnbr_ft - write n in stdout.
*/

void	ft_putnbr_fd(int n, int fd)
{
	int		n_ascii;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n_ascii = (n % 10) * -1;
		n /= -10;
	}
	else
	{
		n_ascii = n % 10;
		n /= 10;
	}
	if (n)
		ft_putnbr_fd(n, fd);
	ft_putchar_fd(n_ascii + '0', fd);
}
