/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 22:06:34 by anonymous          #+#    #+#             */
/*   Updated: 2016/11/09 22:15:07 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** int ft_isalpha(int c);
**
** NAME
**	ft_isalpha -- alphabetic character test
** DESCRIPTION
**	The ft_isalpha() function tests if the value is between
**	'A' and 'Z' or 'a' and 'z' included
**	The value of the argument must be representable as an unsigned char or the
**	value of EOF.
** RETURN VALUES
**	The ft_isalpha() function returns zero if the character tests false and
**	returns non-zero if the character tests true.
*/

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
