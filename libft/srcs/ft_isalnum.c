/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:44:08 by anonymous          #+#    #+#             */
/*   Updated: 2016/11/10 22:24:42 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** int ft_isalnum(int c);
**
** NAME
**	ft_isalnum -- alphanumeric character test
** DESCRIPTION
**	The ft_isalnum() function tests for any character that needs to be either
**	a digit or alpha.  The value of the argument must be representable as an
**	unsigned char or the value of EOF.
** RETURN VALUES
**	The ft_isalnum() function returns zero if the character tests false and
**	returns non-zero if the character tests true.
*/

int	ft_isalnum(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9'));
}
