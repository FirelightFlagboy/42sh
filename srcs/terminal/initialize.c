/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:20:30 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/05 14:49:20 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

/*
** initialize terminal
** sh
** set pwd
** term
** termios flags
** return 1 if pb
*/

static inline int	ft_save_fd(t_sh *sh)
{
	sh->basic_fd[STDIN_FILENO] = dup(STDIN_FILENO);
	sh->basic_fd[STDOUT_FILENO] = dup(STDOUT_FILENO);
	sh->basic_fd[STDERR_FILENO] = dup(STDERR_FILENO);
	sh->basic_fd[3] = dup(sh->ttfd);
	return (0);
}

int					initialize(t_sh **sh)
{
	char	*name;
	char	*env;

	if (!(name = ttyname(STDIN_FILENO)))
		exit(!(ft_eprintf("42sh: could not retrieve ttyname.\n") == -2));
	if (((*sh)->ttfd = open(name, O_RDWR)) == -1)
		exit(!(ft_eprintf("42sh: could not retrieve tty.\n") == -2));
	(!(get_env_val(sh, "PWD"))) ? set_pwd_env_var(sh) : (0);
	do_setenv(sh, "SH", get_env_val(sh, "PWD"));
	if (!(env = get_env_val(sh, "TERM")) || !env[0])
		do_setenv(sh, "TERM", (env = "xterm-256color"));
	if (tgetent(NULL, env) == -1\
	|| tcgetattr(STDIN_FILENO, &(*sh)->term->term) == -1)
		return (1);
	if (tcgetattr(STDIN_FILENO, &(*sh)->official) == 1)
		return (1);
	ft_save_fd(*sh);
	(*sh)->term->term.c_lflag &= ~(ECHO | ICANON);
	if (tcsetattr(STDIN_FILENO, TCSADRAIN, &(*sh)->term->term) == -1)
		return (1);
	(*sh)->term->tc_ok = 1;
	return (0);
}
