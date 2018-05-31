/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interceptsig.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 21:45:23 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/02 15:05:34 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** intercept signal
*/

#include "sh.h"

void	handler(int sig)
{
	(void)sig;
}

void	interceptsig(void)
{
	int		i;

	i = 0;
	while (i < 32)
		signal(i++, handler);
	signal(SIGINT, fctsig);
	signal(SIGWINCH, sig_resize);
	signal(SIGKILL, handler_quit);
	signal(SIGTERM, handler_quit);
	signal(SIGQUIT, handler_quit);
	signal(SIGSEGV, handler_quit);
	signal(SIGSEGV, SIG_DFL);
	signal(SIGPIPE, SIG_DFL);
}
