/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:04:18 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/03 11:49:41 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

char			get_extention(t_c_tab *list)
{
	struct stat buf;

	if ((lstat(list->content, &buf)) != 0)
		stat(list->content, &buf);
	if (S_ISDIR(buf.st_mode))
		return ('/');
	else if (S_ISLNK(buf.st_mode))
		return ('@');
	else if (S_ISSOCK(buf.st_mode))
		return ('=');
	else if (S_ISFIFO(buf.st_mode))
		return ('|');
	else if (S_ISWHT(buf.st_mode))
		return ('%');
	else if (list->perm == NULL)
		return (0);
	else if (ft_strchr(list->perm, 'x'))
		return ('*');
	else if (list->perm[0] == 'c')
		return ('%');
	else if (list->perm[0] == 'b')
		return ('#');
	return (0);
}

static char		*set_color(t_c_tab *list)
{
	if (list->perm == NULL)
		return ("\033[0m");
	if (ft_strncmp(list->perm, "drwxrwxrwxt", 10) == 0)
		return (TEMP);
	else if (list->perm[0] == 'p')
		return (YELL);
	else if (list->perm[0] == 'd')
		return (RED);
	else if (list->perm[0] == 'l')
		return (LCYA);
	else if (list->perm[0] == 'c')
		return (CHAR);
	else if (list->perm[0] == 's')
		return (DGRE);
	else if (list->perm[0] == 'b')
		return (CHAR);
	else if (ft_strchr(list->perm, 'x'))
		return (LGRE);
	return ("\033[0m");
}

void			ft_print(t_c_tab *list)
{
	char	*color;
	char	ext;

	color = set_color(list);
	ext = get_extention(list);
	if (list->name != NULL)
		ft_printf("\033[0m%s%s\033[0m%c", color, list->name, ext);
}
