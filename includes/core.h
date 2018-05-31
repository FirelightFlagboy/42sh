/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:35:20 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/28 16:01:00 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "sh_struct.h"

void				check_if_good_place(void);
void				print_prompt(t_sh **sh, char *prompt);
char				*get_git_branch(void);
void				build_prompt(t_sh **sh);
t_sh				*gtsh(char **env);
void				initenv(t_sh *sh, char **env);
int					validate_and_prep_cmd(t_sh **sh);
int					interpret_line(char *cmd);
char				*loop_through_paths(char ***paths, int *i, char *cmd);
int					command_not_found(t_sh **sh);
int					permission_denied(t_sh **sh, t_bool name, char *path);
int					must_exec(t_sh **sh, char *exec, char **ptr,\
		char **env);
void				print_env(t_envl *env_list);
t_envl				*createenv(char **env);
void				no_file_or_dir(t_sh **sh, t_bool name);
void				not_a_dir(t_sh **sh);
#endif
