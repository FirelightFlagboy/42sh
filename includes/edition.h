/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edition.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:47:40 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/03 13:48:11 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITION_H
# define EDITION_H

# include "sh_struct.h"

/*
**	Edition
*/

void				ft_printbuffer(t_sh **sh);
int					ft_linesize(void);
void				move_right(t_sh **sh, char *buff, int offset);
void				move_left(t_sh **sh);
void				back_to_prompt(t_sh **sh, int keep);
void				clear_cmdline(t_sh **sh);
void				goto_endcmdline(t_sh **sh);
int					ft_isfirstline(t_sh **sh);
int					ft_currentline(t_sh **sh);
int					ft_getpart(t_sh **sh, char **str);
void				cmd_rewrite(t_sh **sh);
#endif
