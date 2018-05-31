/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_output.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 08:55:57 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/24 16:31:53 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		ft_redir_output(t_token *token, int index, int tfd[10])
{
	int		old;
	int		new;
	int		opf;
	char	*str;

	old = STDOUT_FILENO;
	if (token[index - 1].name == IO_NUMBER)
		old = token[index - 1].value[0] - '0';
	opf = O_APPEND;
	if (token[index].name == GREAT)
		opf = O_TRUNC;
	if (!(str = ft_get_arg(token[index + 1])))
		return (ft_warnx_errn("42sh", (g_errn = ERR_MALLOC)));
	if ((new = open(str, opf | OP_FLAGS_W, CREATE_FLAGS)) < 0)
	{
		ft_eprintf("42sh : %s : error open\n", str);
		free(str);
		return (1);
	}
	free(str);
	ft_dup_redir(new, old, tfd);
	return (0);
}
