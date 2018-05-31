/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:32:41 by anonymous          #+#    #+#             */
/*   Updated: 2018/04/24 16:13:24 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static inline void		put_2_page(t_c_tab *list, struct s_put *p)
{
	ft_putstr(tgoto(tgetstr("ch", NULL), 0, p->max_len + 1));
	p->c_line++;
	p->len = ft_strlen(list->name) + 1;
	if (p->len > p->m_len)
		p->m_len = p->len;
	if (list->cursor == 0)
		ft_print(list);
	else
	{
		ft_printf("\033[7;92m%s%c\033[0m", list->name, get_extention(list));
	}
}

static inline int		print_page(size_t c_page, size_t a_page)
{
	ft_putstr(tgetstr("do", NULL));
	ft_printf(" \033[95mPAGE : %d / %d\033[0m", c_page, a_page);
	ft_putstr(tgetstr("up", NULL));
	return (1);
}

static inline void		put_page(t_c_tab *tmp, size_t c_page, size_t a_page)
{
	struct s_put		p;
	size_t				move_up;

	p.max_len = 0;
	p.c_col = 1;
	ft_putstr(tgetstr("up", NULL));
	while (tmp && tmp->page == c_page)
	{
		move_up = 0;
		p.c_line = 1;
		p.m_len = 0;
		while (tmp && tmp->col == p.c_col && tmp->page == c_page)
		{
			put_2_page(tmp, &p);
			tmp = tmp->next;
			ft_putstr(tgetstr("do", NULL));
			move_up++;
		}
		((p.c_col == 1) ? (print_page(c_page, a_page)) : (0));
		if (move_up)
			ft_putstr(tgoto(tgetstr("UP", NULL), 0, move_up));
		p.max_len += p.m_len + 2;
		p.c_col++;
	}
	ft_putstr(tgetstr("do", NULL));
}

int						put_options_2(t_c_tab *list, size_t a_page, size_t val)
{
	size_t				c_page;
	char				*buff[5];

	c_page = list->page;
	while (list->prev && list->page == c_page)
		list = list->prev;
	(list->prev ? list = list->next : list);
	put_page(list, c_page, a_page);
	ft_putstr(tgetstr("up", NULL));
	if (val == 0 && read(0, buff, 5) && (unsigned int)*buff != BTN_TAB)
		return (0);
	else if (val == 0)
	{
		list->cursor = 1;
		put_options(list, 1);
	}
	return (1);
}

/*
**			nb_pages is on c_utils4.c
*/

int						put_options(t_c_tab *list, size_t val)
{
	size_t				a_page;

	ft_putstr(tgetstr("do", NULL));
	if (val == 0)
		list->cursor = 0;
	else
		while (list && list->cursor != 1)
			list = list->next;
	if (!list)
		return (0);
	a_page = nb_pages(list);
	return (put_options_2(list, a_page, val));
}
