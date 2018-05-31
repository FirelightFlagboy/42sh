/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:48:22 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/28 10:41:00 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HISTORY_H
# define HISTORY_H

# include "sh_struct.h"

/*
**	History
*/
void				hist_add_from_str(char *str);
void				hist_add(t_sh **sh);
void				history(t_sh **sh, unsigned int key);
int					print_history(t_sh **sh);
char				*history_search_first_match(t_sh **sh, char *s);
int					replace_double_exclamation(t_sh **sh, char *tmp);
int					replace_single_exclamation(char **cmd);
void				replace_ation(t_sh **sh, char *cmd);
void				set_hist_of_index(t_sh **sh, int index);
t_h_lst				*hist_at_index(t_sh **sh, int index);
int					no_history_err(char *arg);
char				*history_search_first_arg_match(t_sh **sh, char *s);
int					single_excl_type(char *str);
#endif
