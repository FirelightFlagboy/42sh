/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 13:20:05 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/11 08:35:21 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

size_t	read_count_word(char *s, char *sep, int escape)
{
	int		iw;
	size_t	count;
	char	lc;

	iw = 0;
	count = 0;
	lc = 0;
	while (*s)
	{
		if ((lc != '\\' || escape) && ft_strchr(sep, *s))
			iw = 0;
		else if (!iw)
		{
			iw = 1;
			count++;
		}
		lc = *s;
		s++;
	}
	return (count);
}

size_t	read_len_word(char *s, char *sep, int escape)
{
	size_t	len;
	char	lc;

	len = 0;
	lc = 0;
	while (*s)
	{
		if ((lc != '\\' || escape) && ft_strchr(sep, *s))
			break ;
		if ((lc != '\\' || escape))
			len++;
		lc = *s;
		s++;
	}
	return (len);
}

void	read_do_dup(char **t, char **ts, char *sep, int escape)
{
	char	*s;
	char	*str;
	char	lc;

	s = *ts;
	str = *t;
	while (*s)
	{
		if ((lc != '\\' || escape) && ft_strchr(sep, *s))
			break ;
		if ((*s != '\\' || escape))
		{
			*str = *s;
			str++;
		}
		lc = *s;
		s++;
	}
	*str = 0;
	*ts = s;
}

void	read_do_split(char **t, char *s, char *sep, int escape)
{
	int		len;

	while (*s)
	{
		while (*s && ft_strchr(sep, *s))
			s++;
		len = read_len_word(s, sep, escape);
		if (len == 0)
			break ;
		if (!(*t = (char*)malloc((len + 1) * sizeof(char))))
			return ;
		read_do_dup(t, &s, sep, escape);
		t++;
	}
	*t = NULL;
}

int		read_end(char *s, size_t opt[READ_NB_OPT][2], char **var)
{
	t_sh	*sh;
	char	*sep;
	size_t	nbw;
	char	**t;

	(void)var;
	sh = gtsh(0);
	t = 0;
	sep = 0;
	if (!(sep = ft_get_val(sh, "IFS")))
		ft_asprintf(&sep, "%c \n\t\v", read_getdelim(opt));
	else
		ft_asprintf(&sep, "%c%s \n\t\v", read_getdelim(opt), sep);
	nbw = read_count_word(s, sep, opt[0][0]);
	if (!(t = (char**)malloc((nbw + 1) * sizeof(char*))))
		return (1);
	read_do_split(t, s, sep, opt[0][0]);
	read_do_assign(sh, t, var);
	ft_free_tchar(t);
	free(sep);
	return (0);
}
