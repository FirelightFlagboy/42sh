/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:42:52 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/04 15:05:22 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READING_H
# define READING_H

# include "sh_struct.h"

/*
**	Reading
*/
void				clear_prompt(t_sh **sh);
void				read_input(t_sh **sh, char *heredoc);
int					replace_env_vals(t_sh **sh);
void				work_buffer(t_sh **sh, char *buffer);
int					reset_line(t_sh **sh);
#endif
