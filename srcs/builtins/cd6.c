/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd6.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:08:56 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/25 12:10:20 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char	*ft_pass_slash(char *in)
{
	while (*in == '/')
		++in;
	return (in);
}

static char	*ft_dot_dot(char ***top, char **pos, char **out, int isabs)
{
	if ((*top) != pos + 1)
		(*out) = *--(*top);
	else if (isabs)
		(*out) = (*top)[-1];
	else
	{
		ft_strcpy((*out), "../");
		(*out) += 3;
	}
	return (*out);
}

static char	*ft_end_loop(char ***top, char **out, char **in)
{
	*(*top)++ = (*out);
	while (*in && *(*in) != '/')
		*(*out)++ = *(*in)++;
	if (*(*in) == '/')
		*(*out)++ = '/';
	return (*out);
}

static char	*ft_normalize(char *out, char *in, char **pos, char **top)
{
	char	*head;
	int		isabs;

	head = out;
	if ((isabs = (*in == '/')))
		*out++ = '/';
	*top++ = out;
	while (*in)
	{
		in = ft_pass_slash(in);
		if (*in == 0)
			break ;
		if (in[0] == '.' && (in[1] == '/' || in[1] == 0) && (++in))
			continue;
		if (ft_strncmp(in, "..", 2) == 0 && (in[2] == '/' || in[2] == 0)\
		&& (in += 2) && ft_dot_dot(&top, pos, &out, isabs))
			continue;
		if (!ft_end_loop(&top, &out, &in))
			return (NULL);
	}
	*out = '\0';
	if (*head == '\0')
		ft_strcpy(head, "./");
	return (head);
}

char		*ft_path_normalize(char *path)
{
	char		*s;
	char		**p;
	char		**top;
	char		*str;
	char		*npath;

	if (path == NULL)
		return (NULL);
	if (!(p = (char**)malloc((ft_str_count_c(path, '/') + 3) * sizeof(char*))))
		malloc_error();
	top = p;
	npath = NULL;
	if (ft_end_slash(path) == 0)
	{
		npath = ft_strjoin(path, "/");
		path = npath;
	}
	if (!(path = ft_strdup(path))\
	|| !(s = ft_strnew(ft_strlen(path))))
		malloc_error();
	str = ft_normalize(s, path, p, top);
	ft_trim_backslash(s);
	str = ft_strdup(s);
	ft_free_strtab(npath, path, p, s);
	return (str);
}
