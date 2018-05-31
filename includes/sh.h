/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 11:05:51 by anonymous          #+#    #+#             */
/*   Updated: 2018/05/08 09:09:38 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include "sh_inc.h"
# include "ft_printf.h"
# include "libft.h"
# include "sig.h"
# include "sh_define.h"
# include "sh_struct.h"
# include "core.h"
# include "cleaning.h"
# include "env.h"
# include "builtin.h"
# include "reading.h"
# include "lexer_parser.h"
# include "argv.h"
# include "evalcmd.h"
# include "terminall.h"
# include "edition.h"
# include "history.h"
# include "quotes.h"
# include "completion.h"
# include "my_errno.h"
# include "other.h"
# include "hash.h"
# include "debug.h"

extern int g_exit;

/*
** main
*/

int				err(char *str);
int				start(t_sh *sh);

#endif
