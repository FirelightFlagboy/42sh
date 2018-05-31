/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:42:23 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/02 11:36:49 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** initialize
** memory
*/

t_quotes		*init_quotes(t_quotes *q)
{
	q->was_quoted = FALSE;
	q->dquote = FALSE;
	q->squote = FALSE;
	q->bquote = FALSE;
	q->escape = FALSE;
	q->oneline = FALSE;
	q->curly_bracket = FALSE;
	q->parenthesis = FALSE;
	return (q);
}

/*
** more input until quote
** with prompt
** custom signal
*/

char			*ask_for_more_input(t_sh **sh, t_quotes *q)
{
	char	*qt;

	if (q->oneline)
		qt = "";
	ft_strdel(&(*sh)->buff);
	if (q->bquote && (qt = "`"))
		ft_strcpy((*sh)->prompt, "bquote> ");
	else if (q->dquote && (qt = "\""))
		ft_strcpy((*sh)->prompt, "dquote> ");
	else if (q->squote && (qt = "\'"))
		ft_strcpy((*sh)->prompt, "squote> ");
	else if (q->parenthesis)
		ft_strcpy((*sh)->prompt, "subsh> ");
	else if (q->curly_bracket)
		ft_strcpy((*sh)->prompt, "cursh> ");
	else if (q->escape)
		ft_strcpy((*sh)->prompt, "back> ");
	else
		ft_strcpy((*sh)->prompt, "> ");
	(*sh)->inhere = 1;
	print_prompt(sh, (*sh)->prompt);
	read_input(sh, qt);
	return ((*sh)->buff);
}

/*
** loop and ask for input until end of quote
*/

int				do_quotes(t_sh **sh)
{
	char		*t;
	t_quotes	q;

	while (ft_check_quotes((*sh)->buff, init_quotes(&q)))
	{
		(*sh)->tmp_buff = ft_strdup((*sh)->buff);
		t = ask_for_more_input(sh, &q);
		if (t)
		{
			if ((*sh)->tmp_buff)
				ft_asprintf(&t, "%s\n%s", (*sh)->tmp_buff, t);
			else
				t = ft_strdup(t);
		}
		else if ((*sh)->tmp_buff)
			ft_asprintf(&t, "%s\n\n", (*sh)->tmp_buff);
		else
			t = ft_strdup("\0");
		ft_strdel(&(*sh)->buff);
		(*sh)->buff = ft_strdup(t);
		ft_strdel(&t);
		ft_strdel(&(*sh)->tmp_buff);
	}
	return (0);
}
