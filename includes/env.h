/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:39:27 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/24 09:47:07 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "sh_struct.h"

/*
**	Environment list custom struct & functions
*/

void				envladd(t_envl **begin_list, t_envl *new);
t_envl				*envlnew(char *name, char *value);
int					envladd_back(t_envl **begin_list, t_envl *new);
char				*get_env_val(t_sh **sh, char *name);
void				clean_env_list(t_envl **begin_list);
int					env_lst_size(t_envl *begin_list);
void				rebuild_str2env(t_sh **sh);
char				*ft_getenv(t_sh *sh, char *key);
char				*ft_get_val(t_sh *sh, char *key);
#endif
