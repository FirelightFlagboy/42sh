/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:40:26 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/11 08:46:30 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "sh_struct.h"

typedef	int	(*t_builtin_func)(t_sh**);

# define NORETURN _Noreturn void

NORETURN		malloc_error();

# define READ_NB_OPT 4

/*
**	Builtins
*/
int				builtin_env(t_sh **sh);
int				builtin_echo(t_sh **sh);
int				builtin_exit(t_sh **sh);
int				ft_export(t_sh **sh);
int				builtin_getenv(t_sh **sh);
int				builtin_setenv(t_sh **sh);
int				builtin_unsetenv(t_sh **sh);
int				builtin_cd(t_sh **sh);
int				ft_set(t_sh **sh);
int				ft_unset(t_sh **sh);
int				read_main(t_sh **sh);
int				built_history(t_sh **tsh);

/*
** Utils
*/
/*
** Read
*/
void			read_do_assign(t_sh *sh, char **t, char **var);
int				read_end(char *s, size_t opt[READ_NB_OPT][2], char **var);
int				read_work(\
	int stdin, size_t opt[READ_NB_OPT][2], char **var, int buff);
char			read_getdelim(size_t opt[READ_NB_OPT][2]);
char			*read_getprompt(size_t opt[READ_NB_OPT][2]);
int				read_getfd(size_t opt[READ_NB_OPT][2]);
int				read_getopt(char ***tav, size_t opt[READ_NB_OPT][2], char *sot);

/*
** History
*/
int				ft_read(int fd, char **s);
int				hist_check_good(char *file, int flags);
int				load_history_file(t_sh *sh);
void			save_history_file(t_sh *sh);
int				hist_read(t_sh *sh);
char			*get_filename(char **av, t_sh *sh);
int				hist_write(t_sh *sh);
int				hist_append(t_sh *sh);
void			clean_history(t_h_lst **lst);

/*
** Cd
*/
int				pre_prep(char *path[2], int ret[2], int p_option);
int				cd_end(int ret[2], char *path[2]);
void			ft_free_strtab(char *npath, char *path, char **p, char *s);
char			*ft_path_normalize(char *path);
void			ft_trim_backslash(char *s);
int				ft_end_slash(char const *s);
size_t			ft_str_count_c(char const *s, int c);
void			start_moving(t_sh **sh, char *path, struct stat *stats,\
	int p_option);
int				handle_errors(t_sh **sh, char *path, struct stat *stats);
int				look_trough_cd_path(\
	t_sh **sh, char *path, struct stat *st, int opt);
int				permission_denied(t_sh **sh, t_bool name, char *path);
void			not_a_dir(t_sh **sh);
void			no_file_or_dir(t_sh **sh, t_bool name);
int				prep_and_change(t_sh **sh);
int				parse_cd_options(t_sh **sh, int *p_option, char **path);
void			change_symlink_directory(t_sh **sh, char *path);

/*
** Other
*/
int				get_strn_pos(char **str, char *str2, int n);

/*
** export, env
*/
void			create_or_set(t_sh *sh, char *arg);
void			set_valeur(t_sh *sh, char *arg);
void			set_guillemets(t_sh *sh, char *arg);
void			initial_export(t_sh *sh, char *var, char *val);
t_locvar		*new_locvar(t_sh *sh, char *var, char *val);
int				type_of_export(char *str);
t_locvar		*get_locvar_pos(t_sh *sh, char *var);
void			create_or_export(t_sh *sh, char *arg);
void			export_valeur(t_sh *sh, char *arg);
void			export_guillemets(t_sh *sh, char *arg);
void			change_env_export(t_sh *sh, char *var, char *val);
int				ft_lauch(char *path, char **av, char **env);
void			join_back(char ***split_tab, char **new, int *size, int *i);
void			do_setenv(t_sh **sh, char *name, char *value);
int				op_setenv(char **cmd);
int				op_ignore(char **cmd);
void			print_env(t_envl *env_list);
int				op_cmd(char **cmd);
void			print_setenv(char **cmd);
void			work_as_newenv(char **cmd, t_sh **sh);
void			work_with_alterenv(char **cmd, t_sh **sh);
void			work_environ_and_display(char **cmd, t_sh **sh,\
	t_env_s *env_s);
int				is_setenv(char *a);
int				is_ignore(char *a);
char			**remove_duplicate_envs(char **env);
size_t			setenvs_count(char **cmd);
char			**build_tmp_environment(char **cmd);
void			execute_further(t_sh **sh, char **cmd, char ***env);
char			**join_envs(char **env, char **new);
char			**get_command(char **command);
char			**ft_splittreat(char *cmd, char c);
int				env_var_error_checking(char *env_str);
#endif
