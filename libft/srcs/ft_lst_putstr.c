/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 01:45:41 by anonymous          #+#    #+#             */
/*   Updated: 2016/12/31 00:38:15 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

/*
** void ft_lst_putstr(const t_list *l);
**
** DESCRIPTION
**	Print the content of all the elements of the list `l'
** PARAM. #1 - `l'
**	The list.
** RETURN
**	Nothing.
*/

void	ft_lst_putstr(const t_list *l)
{
	while (l != NULL)
	{
		ft_putstr(l->content);
		ft_putchar('\n');
		l = l->next;
	}
}
