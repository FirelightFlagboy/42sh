/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 11:27:20 by anonymous          #+#    #+#             */
/*   Updated: 2016/11/13 11:30:19 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** int ft_isupper(int c);
**
** NAME
**	ft_isupper -- alphabetic character test
** DESCRIPTION
**	The ft_isupper() function tests for any upper-case letter.
**	The value of the argument must be representable as an unsigned char or the
**	value of EOF.
** RETURN VALUES
**	The ft_isupper() function returns zero if the character tests false and
**	returns non-zero if the character tests true.
*/

int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}
