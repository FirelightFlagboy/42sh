/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 16:08:16 by anonymous          #+#    #+#             */
/*   Updated: 2017/01/03 16:08:47 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** int ft_abs(int n);
*/

int	ft_abs(int n)
{
	if (n >= 0)
		return (n);
	return (-n);
}