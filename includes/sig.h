/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:22:33 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/18 11:54:09 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIG_H
# define SIG_H

# include <stdlib.h>
# include <signal.h>
# include <sys/ioctl.h>
# include "sh_struct.h"
# include "sh_define.h"
# include "core.h"
# include "terminall.h"
# include "completion.h"

extern int g_exit;

void	handler_child(int sig);
void	handler_(int sig);
void	handler_quit(int sig);
void	sig_resize(int s_num);
void	fctsig(int s_num);
void	interceptsig(void);
#endif
