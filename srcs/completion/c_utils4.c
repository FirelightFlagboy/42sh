/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_utils4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 16:44:18 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/28 16:34:47 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void				tab_cursor_fix(t_c_tab **list)
{
	t_c_tab			*tmp;

	tmp = (*list);
	while (tmp)
	{
		if (tmp->prev == NULL)
			tmp->cursor = 1;
		else
			tmp->cursor = 0;
		tmp = tmp->next;
	}
}

int					check_dir(char *tmp)
{
	struct stat		data;

	if (lstat(tmp, &data) == -1)
		return (0);
	if (S_ISDIR(data.st_mode))
		return (1);
	return (0);
}

size_t				nb_pages(t_c_tab *tmp)
{
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->page);
}

int					check_winsize(t_sh **sh, t_c_tab *list)
{
	struct winsize	w;
	t_c_tab			*tmp;

	tmp = list;
	if (ioctl(0, TIOCGWINSZ, &w) == 0)
	{
		while (tmp)
		{
			if (ft_strlen(tmp->name) > w.ws_col - 1)
			{
				ft_put2str(tgetstr("up", NULL), tgetstr("up", NULL));
				try_up(sh);
				ft_putstr(tgoto(tgetstr("ch", NULL), 0,
							(*sh)->term->prompt_len));
				ft_putstr((*sh)->buff);
				(*sh)->term->tc_in = ft_strlen((*sh)->buff);
				clean_list(list);
				get_list(NULL, 1);
				return (0);
			}
			tmp = tmp->next;
		}
		return (1);
	}
	return (0);
}

int					treat_tab_c(size_t *v, t_sh **sh, t_c_tab **list)
{
	tab_term(1, NULL, 0);
	(((*list)) ? ((*list)) = move_select(((*list)), (*v)) : NULL);
	if ((*v) == 0 && (binary_directories(*sh)))
	{
		if (!(*list = binary_directory(*list, *sh)))
			if (!(((*list)) = tab_binary(((*list)), *sh))
					|| !((*list))->content)
				return (-1);
	}
	else if ((*v) == 0 && (!(((*list)) = search_on_dir(".", *sh, NULL, 1))
				|| !((*list))->content))
		return (-1);
	if (check_winsize(sh, *list) == 0)
		return (0);
	if ((*v) == 0 && !(((*list)) = define_pading(((*list)), &(*v))))
		return (0);
	if ((((*v) = ((*v) != 69 ? ((*v)) : (69))) || !(*v))
			&& !put_options(((*list)), (*v)))
		return (0);
	((*v) = ((*v) != 69 ? (1) : (69)));
	return (1);
}
