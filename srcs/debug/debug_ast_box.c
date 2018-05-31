/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_ast_box.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:11:22 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/09 15:11:31 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			debug_max_width(t_ast *node)
{
	int	left;
	int	right;

	if (node == NULL)
		return (0);
	left = debug_max_width(node->left_son);
	right = debug_max_width(node->right_son);
	return (left > right ? left + 1 : right + 1);
}

void		debug_draw_box_up(t_ast *node, char *s)
{
	char	*t;
	int		nb;
	int		i;

	nb = debug_max_width(node) * 5;
	i = -1;
	t = s;
	s += ft_sprintf(s, "╔");
	while (++i < nb && s - t < 128)
	{
		if (i == nb / 2)
			s += ft_sprintf(s, " ast ");
		else
			s += ft_sprintf(s, "═");
	}
	s += ft_sprintf(s, "╗");
	ft_eprintf("%s\n║\n", t);
}

int			debug_draw_box_down(t_ast *node, char *s)
{
	char	*t;
	int		nb;
	int		i;

	nb = debug_max_width(node) * 5;
	t = s;
	i = -1;
	s += ft_sprintf(s, "╚");
	while (++i < nb && s - t < 128)
	{
		if (i == nb / 2)
			s += ft_sprintf(s, " ast ");
		else
			s += ft_sprintf(s, "═");
	}
	s += ft_sprintf(s, "╝");
	ft_eprintf("║\n%s\n\n", t);
	return (i);
}
