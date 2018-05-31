/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:25:29 by anonymous          #+#    #+#             */
/*   Updated: 2016/11/09 21:38:30 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** int isprint(int c);
**
** NAME
**	ft_isprint -- printing character test (space character inclusive)
** DESCRIPTION
**	The ft_isprint() function tests for any printing character, including
**	space (` '). The value of the argument must be representable as an
**	unsigned char or the value of EOF.
** RETURN VALUES
**	The ft_isprint() function returns zero if the character tests false and
**	returns non-zero if the character tests true.
*/

int	ft_isprint(int c)
{
	return (c >= ' ' && c < 127);
}
