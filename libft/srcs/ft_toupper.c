/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:58:46 by anonymous          #+#    #+#             */
/*   Updated: 2016/11/09 21:18:17 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** int ft_toupper(int c);
**
** DESCRIPTION
**	The ft_toupper() function converts a lower-case letter to the
**	corresponding upper-case letter.
**	The argument must be representable as an unsigned char or the value of EOF.
** RETURN VALUES
**	If the argument is a lower-case letter, the toupper() function returns the
**	corresponding upper-case letter if there is one; otherwise, the argument
**	is returned unchanged.
*/

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	return (c);
}
