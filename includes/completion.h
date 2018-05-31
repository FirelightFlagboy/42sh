/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:59:31 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/24 16:44:49 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPLETION_H
# define COMPLETION_H

# include "sh_struct.h"

/*
**	Completion
*/

void				tab_completion(t_sh **sh, t_c_tab *list, size_t val);
size_t				binary_directories(t_sh *sh);
char				*search_cmd(t_sh *sh);
t_c_tab				*search_on_dir(char *path, t_sh *sh, t_c_tab *list,
					size_t bin);
t_c_tab				*cmd_option(char *cmd, t_c_tab *list);
t_c_tab				*define_pading(t_c_tab *list, size_t *val);
int					put_options(t_c_tab *list, size_t val);
void				put_question(size_t i);
struct s_pad		start_pad(struct winsize w, size_t nb_files);
t_c_tab				*move_select(t_c_tab *list, size_t val);
t_c_tab				*tab_binary(t_c_tab *list, t_sh *sh);
t_c_tab				**init_left(t_c_tab **tmp, size_t *c, size_t *l,
					size_t *page);
t_c_tab				**init_right(t_c_tab **tmp, size_t *c, size_t *l,
					size_t *page);
int					treat_tab_c(size_t *v, t_sh **sh, t_c_tab **list);
void				tab_term(int v, t_sh *sh, int put);
void				tab_lst_sort(t_c_tab **begin_list);
int					check_dir(char *tmp);
t_c_tab				*tab_name(t_c_tab *list, char *cmd);
void				ft_print(t_c_tab *list);
void				get_info(t_c_tab *list);
char				get_extention(t_c_tab *list);
int					get_dir(t_sh **sh);
t_c_tab				*get_list(t_c_tab *list, int i);
void				clean_list(t_c_tab *list);
void				try_up(t_sh **sh);
size_t				nb_pages(t_c_tab *tmp);
int					check_winsize(t_sh **sh, t_c_tab *list);
t_c_tab				*name_completion(t_c_tab *list, char **str);
char				*fix_cmdname(char **cmd);
t_c_tab				*get_matching(t_c_tab *list, char *path,
		char *tofind);
char				*completion_buffer(t_c_tab *list, t_sh *sh,
		char *tmp);
struct s_pad		get_largest(struct s_pad pad, t_c_tab *list);
t_c_tab				*get_matching_binary(t_c_tab *list, char *path,
		char *tofind);
t_c_tab				*binary_directory(t_c_tab *list, t_sh *sh);
t_c_tab				*name_fill(t_c_tab *list, char *path, char *tofind);
void				tab_cursor_fix(t_c_tab **list);
int					big_enough(t_c_tab *list);
void				begin_resize_tab(t_c_tab **list, size_t number);
void				put_space(t_sh **sh);
int					compare_tab_str(char *s1, char *s2, size_t len);

#endif
