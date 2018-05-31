/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setterm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anonymous <anonymous@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 23:06:13 by anonymous          #+#    #+#             */
/*   Updated: 2018/03/05 23:06:32 by anonymous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh.h"

int		term_trigger(t_sh **sh, int off)
{
	if ((*sh)->term->tc_ok)
	{
		if (off)
			(*sh)->term->term.c_lflag |= (ICANON | ECHO);
		else
			(*sh)->term->term.c_lflag &= ~(ICANON | ECHO);
		if (tcsetattr(STDIN_FILENO, TCSADRAIN,
			&((*sh)->term->term)) == -1)
			return (1);
	}
	return (0);
}
