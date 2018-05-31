/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edition_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:42:40 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/02 14:27:12 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int			ft_numberline(t_sh **sh)
{
	char	*tmp;
	size_t	len;
	int		i;
	size_t	l_line;

	i = 0;
	ft_getpart(sh, &tmp);
	len = ft_strlen(tmp);
	l_line = ft_linesize();
	while (len >= l_line)
	{
		len -= l_line;
		++i;
	}
	ft_strdel(&tmp);
	return (i);
}

int			ft_linesize(void)
{
	struct winsize w;

	ioctl(0, TIOCGWINSZ, &w);
	return (w.ws_col);
}

int			ft_currentline(t_sh **sh)
{
	char	**argv;
	int		i;
	int		i2;
	int		i3;
	char	*tmp;

	i = -1;
	if (!(*sh)->buff)
		return (0);
	if (!(argv = ft_strsplitin((*sh)->buff, '\n')))
		malloc_error();
	ft_getpart(sh, &tmp);
	while (argv[++i] && ft_strncmp(argv[i], tmp, ft_strlen(argv[i])) != 0)
		;
	i3 = (*sh)->term->tc_in;
	i2 = 0;
	while (i2 < i)
		i3 -= ft_strlen(argv[i2++]);
	ft_strdel(&tmp);
	ft_str2del(&argv);
	return (i3);
}

int			ft_isfirstline(t_sh **sh)
{
	int i;

	i = (*sh)->term->tc_in;
	if (!(*sh)->buff)
		return (1);
	if (i < 0)
		return (1);
	while (i > 0)
	{
		if ((*sh)->buff[i] == '\n' && i != (*sh)->term->tc_in)
			return (0);
		--i;
	}
	return (1);
}

int			ft_getpart(t_sh **sh, char **str)
{
	int		i;
	char	**array;
	int		i2;
	int		i3;

	i = 0;
	i2 = 0;
	i3 = 0;
	if (!(*sh)->buff)
		return (-1);
	if (!(array = ft_strsplitin((*sh)->buff, '\n')))
	{
		str ? ft_strdup("\0") : NULL;
		return (0);
	}
	i2 = 0;
	while (i2 < (*sh)->term->tc_in && (*sh)->term->tc_in != 0)
		i2 += ft_strlen(array[i++]);
	if (i != 0)
		i--;
	i3 = ft_strlen(array[i]);
	str ? *str = ft_strdup(array[i]) : NULL;
	ft_str2del(&array);
	return (i3);
}
