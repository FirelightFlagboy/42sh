/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 16:26:36 by ybensimo          #+#    #+#             */
/*   Updated: 2018/05/02 16:35:39 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "sh.h"

void	malloc_error(void)
{
	ft_dprintf(2, "42sh: malloc error, exiting.\n");
	exit(EXIT_FAILURE);
}
