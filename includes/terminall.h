/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminall.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:45:09 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/30 10:00:45 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINALL_H
# define TERMINALL_H

# include "sh_struct.h"

/*
**	Terminall
*/

int					initialize(t_sh **sh);
void				set_pwd_env_var(t_sh **sh);
int					term_trigger(t_sh **sh, int off);
int					ft_numberline(t_sh **sh);
void				move_page(t_sh **sh, uint key);
void				move_cursor_sides(t_sh **sh, unsigned int key);
void				move_cursor_alt(t_sh **sh, unsigned int key);
void				modify_buffer(t_sh **sh, unsigned int key);
void				clean_buffer(t_sh **sh);
void				cut_line(t_sh **sh, unsigned int key);
void				paste(t_sh **sh);
void				copy(t_sh **sh);
int					uninitialize(void);
#endif
