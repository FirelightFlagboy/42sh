/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_completion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:32:47 by anonymous          #+#    #+#             */
/*   Updated: 2018/04/30 09:44:21 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static size_t		verify_btn(char *buff, int rt)
{
	if (rt == -1)
		return (0);
	buff[rt] = 0;
	if (!ft_strcmp(buff, tgetstr("ku", 0)))
		return (8);
	else if (!ft_strcmp(buff, tgetstr("kr", 0)))
		return (6);
	else if (buff[0] == 9)
		return (9);
	else if (!ft_strcmp(buff, tgetstr("kl", 0)))
		return (4);
	else if (!ft_strcmp(buff, tgetstr("kd", 0)))
		return (2);
	else if (buff[0] == 127)
		return (10);
	else if (buff[0] == 10 || buff[0] == 32)
		return (1);
	else if (buff[0] == 47)
		return (47);
	return (0);
}

static void			put_tab(t_c_tab *list, t_sh **sh, size_t v)
{
	char			*res;
	char			*tmp;
	size_t			i;

	tmp = NULL;
	ft_putstr(tgetstr("up", NULL));
	if (v != 1 && v <= 10)
		return (tab_term(2, *sh, 0));
	while (list && list->cursor != 1)
		list = list->next;
	i = ft_strlen((*sh)->buff);
	while (i > 0 && (*sh)->buff[i] != ' ')
		i--;
	if (i != 0)
		tmp = ft_strsub((*sh)->buff, 0, i + 1);
	ft_putstr(tgoto(tgetstr("ch", NULL), 0, (*sh)->term->prompt_len));
	try_up(sh);
	if (!(res = NULL) && list && list->content)
		res = completion_buffer(list, *sh, search_cmd(*sh));
	ft_strdel(&tmp);
	reset_line(sh);
	work_buffer(sh, res);
	ft_strdel(&res);
}

/*
**		binary_directories && search_on_dir are in c_utils.c
**			tab_term && tab_binary is on c_utils3.c
*/

void				tab_completion(t_sh **sh, t_c_tab *list, size_t v)
{
	char			buff[5];
	int				ttc;

	ft_memset(buff, 0, 5);
	tab_term(4, NULL, 0);
	if (get_dir(sh))
		return ;
	while ((!list || (list && (get_list(NULL, 0)))) &&
			(v == 0 || (v != 69 && (ttc = read(0, buff, 5))
			&& (v = verify_btn(buff, ttc)) > 1 && v < 10)))
	{
		ft_memset(buff, 0, 5);
		if ((ttc = treat_tab_c(&v, sh, &list)) == 0)
			break ;
		else if (ttc == -1)
			return (tab_term(2, *sh, 1));
	}
	if (!get_list(NULL, 0))
		return ;
	ft_putstr(tgetstr("up", NULL));
	put_tab(list, sh, v);
	(list ? clean_list(list) : NULL);
	get_list(NULL, 1);
}
