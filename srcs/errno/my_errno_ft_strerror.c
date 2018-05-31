/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_errno_ft_strerror.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 13:41:38 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/24 16:18:20 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_errno.h"

static char	*ft_unknown_code(int errnum)
{
	static char	s[64];
	static char	*p;
	int			i;
	int			l;

	if (!p)
		p = " : code error unknown";
	l = ft_atoi_to_buff(errnum, s);
	i = 0;
	while (p[i])
	{
		s[l + i] = p[i];
		i++;
	}
	s[l + i] = 0;
	return (s);
}

char		*ft_strerror(int errnum)
{
	char *const pth[] = {
		"so far so good", "no path set", "malloc error", "chdir error",\
		"stat error", "no such file or directory", "OLDPWD not set",\
		"Permission denied", "open error", "read error", "size too big",\
		"range error", "error on fork", "bad parsing", "File name too long",\
		"is not a directory", "is not a file", "is a directory", "is a block",\
		"is a pipe", "is a link", "is a socket file", "is a char file",\
		"is a file", "bad argument given", "bad adress", "too much arguments",\
		"missing arguments", "command not found", NULL
	};

	g_errn = ERR_OK;
	if (errnum >= 0 && errnum < LAST)
	{
		return (pth[errnum]);
	}
	return (ft_unknown_code(errnum));
}
