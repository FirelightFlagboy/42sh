/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 09:01:11 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/09 15:42:28 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

void	handler_read(int sig)
{
	signal(SIGINT, handler_read);
	(void)sig;
	ft_eprintf("\nyo\n");
}

int		ft_change_stdin(int stdin, int delim)
{
	struct termios term;

	tcgetattr(stdin, &term);
	term.c_lflag &= ~(ISIG);
	term.c_cc[VEOL2] = 3;
	term.c_cc[VEOL] = delim;
	tcsetattr(stdin, 0, &term);
	return (0);
}

int		read_main(t_sh **sh)
{
	char *const		sopt = "rpudh";
	char			**av;
	int				stdin;
	size_t			opt[READ_NB_OPT][2];
	struct termios	save;

	av = (*sh)->cmd + 1;
	ft_memset(opt, 0, sizeof(opt));
	stdin = STDIN_FILENO;
	if (read_getopt(&av, opt, (char*)sopt))
		return (1);
	if ((stdin = read_getfd(opt)) == -1 || read_getdelim(opt) == -1)
		return (1);
	if (isatty(stdin))
	{
		tcgetattr(stdin, &save);
		ft_change_stdin(stdin, read_getdelim(opt));
	}
	av = (char**)(size_t)\
	read_work(stdin, opt, av, (isatty(stdin)) ? 1024 : 1);
	if (isatty(stdin))
		tcsetattr(stdin, 0, &save);
	return ((int)av);
}
