/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 11:19:25 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/11 08:36:29 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		read_need_to_stop(char *s, int escape, int delim)
{
	char	llc;
	char	lc;
	size_t	len;

	len = ft_strlen(s);
	lc = (len > 0) ? s[len - 1] : 0;
	llc = (len > 1) ? s[len - 2] : 0;
	if (lc != delim)
		return (0);
	if (llc == '\\' && escape == 0)
		return (0);
	return (1);
}

int		read_work_init(size_t opt[READ_NB_OPT][2], char **ts)
{
	char	*prompt;

	if ((prompt = read_getprompt(opt)))
		ft_eprintf("%s", prompt);
	*ts = ft_strdup("\0");
	return (0);
}

int		read_work(int stdin, size_t opt[READ_NB_OPT][2], char **var, int buff)
{
	char	*s;
	char	*tmp;
	char	t[1024 + 1];
	int		r;

	read_work_init(opt, &s);
	while ((r = read(stdin, t, buff)) > 0)
	{
		t[r] = 0;
		if (t[r - 1] == 3 && (r = -1) && ft_charput('\n'))
			break ;
		tmp = s;
		ft_asprintf(&s, "%s%s", s, t);
		free(tmp);
		if (read_need_to_stop(s, opt[0][0], read_getdelim(opt)))
			break ;
	}
	if (r < 0)
	{
		ft_strdel(&s);
		return (-1);
	}
	tmp = (char*)(size_t)read_end(s, opt, var);
	ft_strdel(&s);
	return ((int)tmp);
}
