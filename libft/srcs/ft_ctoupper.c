/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctoupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:56:49 by anonymous          #+#    #+#             */
/*   Updated: 2017/01/03 17:57:17 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_ctoupper(const char c)
{
	if (ft_islower(c))
		return (c - 'a' + 'A');
	return (c);
}
