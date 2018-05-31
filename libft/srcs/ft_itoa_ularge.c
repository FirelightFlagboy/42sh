/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ularge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 23:43:15 by anonymous          #+#    #+#             */
/*   Updated: 2018/04/07 09:55:24 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	do_chars(char *first, char *now, intmax_t number)
{
	while (now >= first)
	{
		*now = number % 10 + '0';
		number /= 10;
		now--;
	}
}

char		*ft_itoa_ularge(intmax_t number)
{
	char	*new;
	int		length;

	if (number == 0)
		return (ft_strdup("0"));
	length = ft_count_umax_digits(number);
	if (!(new = malloc(sizeof(char*) * (length + 1))))
		return (NULL);
	do_chars(new, new + length - 1, number);
	new[length] = '\0';
	return (new);
}
