/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:50:47 by anonymous          #+#    #+#             */
/*   Updated: 2016/11/09 22:33:20 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** int ft_isdigit(int c);
** NAME
**	ft_isdigit  -- decimal-digit character test
** DESCRIPTION
**	The isdigit() function tests for a decimal digit character.
**	The value of the argument must be representable as an unsigned char
**	or the value of EOF.
** RETURN VALUES
**	The ft_isdigit() function return zero if the character tests
**	false and return non-zero if the character tests true.
*/

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
