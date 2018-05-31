/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 10:42:48 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/11 10:05:10 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

static int		cancel_heredoc(t_sh **sh, char *heredoc)
{
	ft_strdel(&(*sh)->buff);
	(*sh)->buff = ft_strdup(heredoc);
	return (reset_line(sh));
}

/*
** Trigger actions
*/

static int		identify_key_2(t_sh **sh, unsigned int key,\
		char *heredoc)
{
	if (key == BTN_LEFT || key == BTN_RIGHT ||
			key == BTN_END || key == BTN_HOME)
		move_cursor_sides(sh, key);
	else if (key == BTN_CTRL_D && (*sh)->inhere)
		return (cancel_heredoc(sh, heredoc));
	else if (key == BTN_CTRL_D)
	{
		if (!(*sh)->buff || ft_strlen((*sh)->buff) == 0)
			handler_quit(0);
		else
			modify_buffer(sh, BTN_DEL);
	}
	else if (key == BTN_ENTER)
	{
		goto_endcmdline(sh);
		return (reset_line(sh));
	}
	return (1);
}

uint			get_key(char *s, int rt, char *t)
{
	if (rt == 1)
		return (*s);
	if ((t = tgetstr("kD", 0)) && ft_strcmp(t, s) == 0)
		return (BTN_DEL);
	if ((t = tgetstr("kh", 0)) && ft_strcmp(t, s) == 0)
		return (BTN_HOME);
	if (ft_strcmp("\x1b\x4f\x46", s) == 0)
		return (BTN_END);
	if (ft_strcmp("\x1b\x1b\x5b\x44", s) == 0)
		return (BTN_ALEFT);
	if (ft_strcmp("\x1b\x1b\x5b\x43", s) == 0)
		return (BTN_ARIGHT);
	if ((t = tgetstr("kr", 0)) && ft_strcmp(t, s) == 0)
		return (BTN_RIGHT);
	if ((t = tgetstr("kl", 0)) && ft_strcmp(t, s) == 0)
		return (BTN_LEFT);
	if ((t = tgetstr("ku", 0)) && ft_strcmp(t, s) == 0)
		return (BTN_UP);
	if ((t = tgetstr("kd", 0)) && ft_strcmp(t, s) == 0)
		return (BTN_DOWN);
	if ((t = tgetstr("kP", 0)) && ft_strcmp(t, s) == 0)
		return (BTN_PAGE_UP);
	if ((t = tgetstr("kN", 0)) && ft_strcmp(t, s) == 0)
		return (BTN_PAGE_DOWN);
	return (1);
}

static int		identify_key(t_sh **sh, char *buff, char *heredoc)
{
	int	rt;
	int	key;

	signal(SIGINT, SIG_IGN);
	tputs(tgetstr("vi", 0), 0, ft_charput);
	rt = 0;
	if (buff[0] == '\e' && (rt = read(STDIN_FILENO, buff + 1, 5)) < 1)
		return (!!ft_eprintf("error read\n"));
	buff[rt + 1] = 0;
	key = get_key(buff, rt + 1, NULL);
	(key != BTN_ENTER && ft_isprint(key)) ? work_buffer(sh, buff) : (0);
	(key == BTN_BACK || key == BTN_DEL) ? modify_buffer(sh, key) : (0);
	(key == BTN_ALEFT || key == BTN_ARIGHT) ? move_cursor_alt(sh, key) : (0);
	(key == BTN_UP || key == BTN_DOWN) ? history(sh, key) : (0);
	(key == BTN_CTRL_K) ? cut_line(sh, key) : (0);
	(key == BTN_CTRL_P) ? work_buffer(sh, (*sh)->clipboard) : (0);
	(key == BTN_CTRL_H) ? copy(sh) : (0);
	(key == BTN_TAB && !(*sh)->inhere) ? tab_completion(sh, NULL, 0) : (0);
	(key == BTN_CTRL_U) ? cmd_rewrite(sh) : (0);
	(key == BTN_PAGE_DOWN || key == BTN_PAGE_UP) ? move_page(sh, key) : (0);
	(key == BTN_CTRL_L) ? clear_prompt(sh) : (0);
	return (identify_key_2(sh, key, heredoc));
}

/*
** Read every keystroke
*/

void			read_input(t_sh **sh, char *heredoc)
{
	char	buff[10];
	int		rt;

	signal(SIGWINCH, sig_resize);
	tputs(tgetstr("ks", 0), 0, ft_charput);
	ft_memset(buff, 0, sizeof(buff));
	while ((rt = read(0, buff, 1)) > 0
	&& (buff[rt] = 0) == 0
	&& identify_key(sh, buff, heredoc))
	{
		signal(SIGINT, (*sh)->sig);
		tputs(tgetstr("ve", 0), 0, ft_charput);
		ft_memset(buff, 0, sizeof(buff));
	}
	tputs(tgetstr("ke", 0), 0, ft_charput);
	tputs(tgetstr("ve", 0), 0, ft_charput);
	signal(SIGINT, (*sh)->sig);
	ft_putchar('\n');
}
