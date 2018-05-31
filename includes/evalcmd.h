/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evalcmd.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 11:17:55 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/04 14:44:45 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVALCMD_H
# define EVALCMD_H

# include "sh_struct.h"
# include "lexer_parser.h"

# ifndef PP_READ
#  define PP_READ 0
# endif

# ifndef PP_WRITE
#  define PP_WRITE 1
# endif

# ifndef CREATE_FLAGS
#  define CREATE_FLAGS S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH
# endif

# ifndef OP_FLAGS_W
#  define OP_FLAGS_W O_WRONLY | O_CREAT | O_CLOEXEC
# endif

/*
** Redir
*/
int			close_pipe(int pfd[2]);
int			ft_dup_agre(int fd_new, int fd_old, int tfd[10]);
int			ft_isall_num(const char *s);
int			ft_rm_heredoc(uintmax_t addr);
void		get_heredoc(t_sh *sh, char *stop);
int			ft_create_heredoc(char *hd_name, uintmax_t addr);
int			ft_close_fd(int tfd[10]);
int			ft_do_redir(int old, int new);
int			ft_close_redir(int fd_old, int tfd[10]);
int			ft_dup_redir(int fd_new, int fd_old, int tfd[10]);
int			ft_redir(t_token *token, int size, int tfd[10]);
int			ft_redir_agre(t_token *token, int index, int tfd[10]);
int			ft_redir_output(t_token *token, int index, int tfd[10]);
int			ft_redir_input(t_token *token, int index, int tfd[10]);

int			ft_eval_cmd_no_fork(t_ast *ast);

void		ft_redir_fd(int old, int new);
void		ft_exit_code(int *res, char *name);
void		evalcmd(t_sh *sh);
int			ft_eval_ast(t_ast *ast);
int			ft_eval_cmd(t_ast *ast);
int			ft_exec_pipe(t_ast *ast, int input, pid_t pgid);
int			ft_eval_pipe(t_ast *ast);
int			ft_eval_direct_cmd(char **av, t_ast *ast);
int			ft_eval_hash(char **av, t_ast *ast);
int			ft_eval_built(char **av, int *rt, t_ast *ast);
#endif
