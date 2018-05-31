/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscntrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 11:16:31 by anonymous          #+#    #+#             */
/*   Updated: 2016/11/13 11:31:04 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** int iscntrl(int c);
**
** DESCRIPTION
**	The ft_iscntrl() function tests for any control character.
**	The value of the argument must be representable as an unsigned char
**	or the value of EOF.
** RETURN VALUES
**	The ft_iscntrl() function returns zero if the character tests false
**	and returns non-zero if the character tests true.
*/

int	ft_iscntrl(int c)
{
	return ((c >= 0 && c < 32) || c == 127);
}
