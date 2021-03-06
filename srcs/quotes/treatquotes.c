/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treatquotes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:42:31 by anonymous          #+#    #+#             */
/*   Updated: 2018/02/28 16:43:31 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static char	*ft_delatfree(char **str, int index)
{
	char	*tmp;

	tmp = *str;
	*str = ft_strndelat(*str, index, 1);
	ft_strdel(&tmp);
	return (*str);
}

char		*remove_quotes(char *temp)
{
	int		index;
	char	c;
	char	*end;

	index = 0;
	c = temp[0];
	end = &temp[index + ft_isquotes(c)];
	end = ft_strdup(end);
	while (end[index])
		if ((end[index] == '\\' && end[index + 1] == '\"' && c != '\'') ||
		(end[index] == '\\' && end[index + 1] == '`' && c != '\'')
				|| (end[index] == '\'' && c == '\'' && end[index + 1]))
			end = ft_delatfree(&end, index);
		else if ((end[index] == '\\' && end[index + 1] == '\\')
			|| (ft_isescaped(end, index + 1) && end[index + 1] == '$'))
		{
			end = ft_delatfree(&end, index);
			((end[index] == '\\') ? (++index) : (0));
		}
		else
			++index;
	if (ft_isquotes(end[index - 1]) && ft_isquotes(c))
		end[index - 1] = '\0';
	ft_strdel(&temp);
	return (end);
}

static char	*test(char *cmd)
{
	int		index;
	char	*str;

	index = 0;
	while (cmd[index])
	{
		if (cmd[index] == '\\')
		{
			str = cmd;
			cmd = ft_strndelat(cmd, index, 1);
			ft_strdel(&str);
			if (cmd[index] == '\\')
				++index;
		}
		else
			++index;
	}
	return (cmd);
}

char		*get_new_part(char *cmd, char **temp)
{
	int index;

	index = 0;
	while (cmd[index])
	{
		if (ft_isquotes(cmd[index]) == 0)
		{
			while (cmd[index] && (!ft_isquotes(cmd[index]) ||\
						(ft_isquotes(cmd[index]) && ft_isescaped(cmd, index))))
				++index;
			*temp = ft_strsub(cmd, 0, index);
			return (&cmd[index]);
		}
		else
		{
			*temp = ft_strsub(cmd, 0, ft_endquo(cmd, index));
			return (&cmd[ft_endquo(cmd, index)]);
		}
	}
	return (NULL);
}

char		*treat_quotes(char *cmd)
{
	char	*tmp;
	char	*endcmd;
	char	*temp;

	endcmd = ft_strnew(1);
	while (cmd && cmd[0] != '\0')
	{
		cmd = get_new_part(cmd, &temp);
		if (temp[0] != '\'')
			temp = quotes_env(temp, NULL);
		if (ft_isquotes(temp[0]))
			temp = remove_quotes(temp);
		else
			temp = test(temp);
		tmp = endcmd;
		endcmd = ft_strjoin(endcmd, temp);
		ft_strdel(&temp);
		ft_strdel(&tmp);
	}
	return (endcmd);
}
