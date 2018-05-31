/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 19:30:00 by anonymous          #+#    #+#             */
/*   Updated: 2016/11/11 11:54:58 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** void	ft_putchar(char c);
**
** NAME
**	ft_putchar - send c to stdout.
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
