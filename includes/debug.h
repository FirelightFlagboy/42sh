/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/08 09:08:40 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/09 15:12:06 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H

# include "sh_struct.h"
# include "limits.h"
# include "stdint.h"

int			debug_max_width(t_ast *node);
void		debug_draw_box_up(t_ast *node, char *s);
int			debug_draw_box_down(t_ast *node, char *s);
void		ft_print_ast(t_ast *node);
void		ft_print_hash(void);
void		ft_print_argv(char **argv);
#endif
