/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 08:14:36 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/03 15:37:11 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** int ft_isspace(int c);
**
** DESCRIPTION
**	The ft_issapce function tests for the white-space character.
**	The standard white-space characters are the following:
**	space ' ', tab '\t', carriage-return '\r', newline '\n',
**	vertical tab '\v', and form-feed '\f'
**	The value of the argument must be representable as an unsigned char
** RETURN VALUES
**	The ft_isspace() function returns zero if the character tests false
**	and returns non-zero if the character tests true.
*/

int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f'
			|| c == '\r' || c == ' ' || c == 0);
}
