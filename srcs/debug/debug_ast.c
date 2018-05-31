/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_ast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 09:07:04 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/11 08:42:15 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void		debug_put_space(char *s, int level)
{
	int		i;
	int		p;
	char	*sa;

	i = -1;
	p = 0;
	sa = s;
	while (++i < (level - 1) * 4 && (s - sa) < 2048)
		*s++ = ' ';
	*s = 0;
}

int			debug_ast(t_ast *node, char *s, int left, int level)
{
	char		*t;
	int			rt;

	if (node == NULL)
		return (0);
	rt = debug_ast(node->left_son, s, 1, level + 1);
	if (left == 1)
		t = "┌";
	else
		t = "└";
	debug_put_space(s, level);
	if (level > 0)
		ft_eprintf("║  %s%s── ", s, t);
	else
		ft_eprintf("║  ");
	ft_eprintf("%s\n", node->node_tokens->value);
	rt += debug_ast(node->right_son, s, 0, level + 1);
	return (rt + 1);
}

void		debug_ast_2_fill(char *s, char *c, int level, char *ctab)
{
	int		i;
	char	*sa;

	if (level)
	{
		i = -1;
		sa = s;
		while (++i < level * 4 - 4 && s - sa < 2038)
		{
			if (i % 4 == 0 && ctab[i / 4])
				s += ft_sprintf(s, "│");
			else
				*s++ = ' ';
		}
		s += ft_sprintf(s, "%s── ", c);
	}
	*s = 0;
}

int			debug_ast_2(t_ast *node, char *s, int mode[2], char *ctab)
{
	int		level;

	level = mode[0] + 1;
	if (!node || level >= 64)
		return (0);
	ctab[level] = 1;
	if (level > 0 && !mode[1])
		ctab[level - 1] = 0;
	debug_ast_2_fill(s, (mode[1] == 0) ? "└" : "├", level, ctab);
	ft_eprintf("║  %s%s\n", s, node->node_tokens->value);
	return (1 +\
	debug_ast_2(node->left_son, s, (int[2]){level, 1}, ctab) +\
	debug_ast_2(node->right_son, s, (int[2]){level, 0}, ctab));
}

void		ft_print_ast(t_ast *node)
{
	char	s[2048];
	char	ctab[64];
	int		nb;
	int		i;

	if (debug_max_width(node) > 8)
	{
		ft_eprintf("\e[31mdebug : ast too deep\e[0m\n");
		return ;
	}
	ft_memset(ctab, 0, sizeof(ctab));
	debug_draw_box_up(node, s);
	ft_eprintf("║ tree :\n");
	nb = debug_ast(node, s, 0, 0);
	ft_eprintf("║ look up :\n");
	nb += debug_ast_2(node, s, (int[2]){-1, 0}, ctab);
	i = debug_draw_box_down(node, s);
	nb += 4;
	ft_eprintf("\e[s\e[%dA\e[%dC", nb + 2, i + 5);
	i = -1;
	while (++i < nb)
		ft_eprintf("║\e[B\e[D");
	ft_eprintf("\e[u");
}
