/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 13:08:24 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/04 14:36:59 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int g_exit;

/*
** get shell
** initialize terminal
** clear terminal
** run shell
** close shell
*/

void	base(t_sh *sh)
{
	char	*home;
	char	pwd[PATH_MAX];
	char	*tmp;

	sh->hist_dir = NULL;
	if (!(home = ft_get_val(sh, "HOME")))
		return ;
	if (ft_access(home, R_OK | F_OK | W_OK))
	{
		ft_eprintf("42sh : %s : %s\n", home, ft_strerror(g_errn));
		return ;
	}
	if (home[0] == '/')
		tmp = ft_strdup(home);
	else
		ft_asprintf(&tmp, "%s/%s", getcwd(pwd, PATH_MAX), home);
	ft_asprintf(&sh->hist_dir, "%s/.42sh_history", tmp);
	ft_strdel(&tmp);
	load_history_file(sh);
}

void	ft_manage_opt(int argc, char **argv, t_sh *sh)
{
	if (argc <= 1)
		return ;
	argv++;
	sh->debug = 0;
	while (*argv)
	{
		if (ft_strcmp(*argv, "ast") == 0)
			sh->debug |= 0b1;
		else if (ft_strcmp(*argv, "argv") == 0)
			sh->debug |= 0b10;
		else if (ft_strcmp(*argv, "hash") == 0)
			sh->debug |= 0b100;
		else if (ft_strcmp(*argv, "redir") == 0)
			sh->debug |= 0b1000;
		argv++;
	}
}

int		main(int argc, char **argv, char **env)
{
	t_sh	*sh;

	sh = gtsh(env);
	ft_manage_opt(argc, argv, sh);
	g_exit = 0;
	if (initialize(&sh))
		return (err("Error: a problem occur durring 42sh initialisation"));
	base(sh);
	uninitialize();
	start(sh);
	closesh(&sh);
	return (sh->ret);
}
