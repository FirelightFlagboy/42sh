/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isblank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 11:14:39 by anonymous          #+#    #+#             */
/*   Updated: 2016/11/13 11:32:35 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** int ft_isblank(int c);
**
** DESCRIPTION
**	The ft_isblank() function tests for a space or tab character.
**	This includes the following: space ' ' and tab '\t'
**	The value of the argument must be representable as an unsigned char
**	or the value of EOF.
** RETURN VALUES
**	The ft_isblank() function returns zero if the character tests false
**	and returns non-zero if the character tests true.
*/

int	ft_isblank(int c)
{
	return (c == '\t' || c == ' ');
}
