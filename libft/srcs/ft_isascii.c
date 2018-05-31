/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:39:18 by anonymous          #+#    #+#             */
/*   Updated: 2016/11/10 22:22:49 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** int	ft_isascii(int c);
**
** int ft_isascii(int c);
** NAME
**	ft_isascii -- test for ASCII character
** DESCRIPTION
**	The ft_isascii() function tests for an ASCII character, which is any
**	character between 0 and octal 0177 inclusive.
*/

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
