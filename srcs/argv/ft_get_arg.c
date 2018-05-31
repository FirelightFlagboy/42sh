/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 11:48:07 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/02 16:35:50 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_env_is_special_case(char *s)
{
	if (*s == '?')
		return (1);
	if (*s == '$')
		return (1);
	if (*s == '!')
		return (1);
	return (0);
}

int		ft_get_env_special_case(char *s)
{
	t_sh *sh;

	sh = gtsh(0);
	if (*s == '?')
		return (sh->ret);
	if (*s == '$')
		return (getppid());
	if (*s == '!')
		return (sh->child);
	return (0);
}

int		ft_get_env_name(char *d, char *s)
{
	int		i;

	i = 1;
	while (s[i] && ft_isspace(s[i]) == 0\
		&& (s[i] != '"' && s[i] != '\'' && s[i] != '/' && s[i] != '\\'))
	{
		d[i - 1] = s[i];
		i++;
		if (s[i - 1] == '?' || s[i - 1] == '!' || s[i - 1] == '$')
			break ;
	}
	return (i);
}

char	*ft_get_arg(t_token token)
{
	int		len;
	char	*s;

	s = token.value;
	len = ft_len_arg(s);
	if (!(s = (char*)malloc((len + 1) * sizeof(char))))
		malloc_error();
	s[len] = 0;
	ft_fill_arg(s, token.value);
	return (s);
}
