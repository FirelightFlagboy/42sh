/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 11:29:42 by anonymous          #+#    #+#             */
/*   Updated: 2016/11/13 11:30:13 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** int ft_islower(int c);
**
** NAME
**	ft_islower -- alphabetic character test
** DESCRIPTION
**	The ft_islower() function tests for any lower-case letter.
**	The value of the argument must be representable as an unsigned char or the
**	value of EOF.
** RETURN VALUES
**	The ft_islower() function returns zero if the character tests false and
**	returns non-zero if the character tests true.
*/

int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}
