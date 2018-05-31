/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:36:16 by anonymous          #+#    #+#             */
/*   Updated: 2016/11/10 22:25:54 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** int ft_tolower(int c);
**
** DESCRIPTION
**	ft_tolower(int c) converts a given letter to lowercase
** RETURN VALUES
**	This function returns lowercase equivalent to c,
**	if such value exists, else c remains unchanged.
**	The value is returned as an int value that can be implicitly casted to char.
*/

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 'a' - 'A');
	return (c);
}
