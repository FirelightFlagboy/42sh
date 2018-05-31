/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 11:23:56 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/27 16:12:42 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGV_H
# define ARGV_H

# include "sh_inc.h"
# include "lexer_parser.h"

/*
** get argument()
*/
int		ft_get_env_special_case(char *s);
int		ft_env_is_special_case(char *s);
int		ft_get_argv(char ***argv, t_token *tk, int size_token);
char	*ft_get_arg(t_token	token);
int		ft_len_arg(char *arg);
int		ft_eval_cmd(t_ast *ast);
void	ft_fill_arg(char *d, char *s);
int		ft_get_env_name(char *d, char *s);
#endif
