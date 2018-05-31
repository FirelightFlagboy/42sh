/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:49:12 by fbenneto          #+#    #+#             */
/*   Updated: 2018/04/24 16:45:20 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUOTES_H
# define QUOTES_H

# include "sh_struct.h"

/*
**	Quotes
*/
int					ft_find_char(char **str, int c);
int					ft_find_char_rc(char **str, int c);
int					ft_check_p1(char **s, t_quotes *q);
int					ft_check_quotes(char *s, t_quotes *q);

char				*quotes_env(char *str, t_sh *sh);
int					do_quotes(t_sh **sh);
int					ft_isescapechar(char c);
char				**splitquote_str2(char *cmd);
int					ft_parenthesis(char **s);
int					ft_curly_bracket(char **s);
int					ft_dquote(char **s);
int					ft_quote(char **s);
int					ft_bquote(char **s);
int					ft_isinc(char *s, t_quotes *q);
#endif
