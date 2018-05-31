/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 21:28:08 by eduriez           #+#    #+#             */
/*   Updated: 2018/05/02 13:32:12 by eduriez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_PARSER_H
# define LEXER_PARSER_H

# include "libft.h"
# include "ft_printf.h"
# include "sh_struct.h"

typedef int			(*t_lex_word_func)(const char*, int*, t_token_list**);

int					ft_strchr_index(const char *s, int c);

int					ft_is_start_op(const char c);
int					ft_isspace_separator(const char c);
t_token_list		*ft_lex_cmd(const char *cmd_user);

int					ft_process_word(const char *cmd_user,
									int *i,
									t_token_list **list_tokens);

int					ft_lex_quotes(const char *start_quote,
								int *nb_chars_in_word);

int					ft_lex_simple_quotes(const char *start_quote,
										int *nb_chars_in_word);

int					ft_lex_double_quotes(const char *start_quote,
										int *nb_chars_in_word);

t_token				ft_create_token(const t_token_family family,
									const t_token_name name,
									char *value);

int					ft_add_token(const t_token token,
								t_token_list **list_tokens);

void				ft_delete_list(t_token_list *list_tokens);
void				ft_delete_ast(t_ast *ast);
t_lex_word_func		ft_get_lex_word_function(const char start_op);

int					ft_manage_and_operators(const char *cmd_user,
											int *op_position,
											t_token_list **list_tokens);

int					ft_manage_or_operators(const char *cmd_user,
										int *op_position,
										t_token_list **list_tokens);

int					ft_manage_semicolon_operators(const char *cmd_user,
												int *op_position,
												t_token_list **list_tokens);

int					ft_manage_newline_operator(const char *cmd_user,
											int *op_position,
											t_token_list **list_tokens);

int					ft_manage_less_operators(const char *cmd_user,
											int *op_position,
											t_token_list **list_tokens);

int					ft_manage_great_operators(const char *cmd_user,
											int *op_position,
											t_token_list **list_tokens);

t_token_list		*ft_find_next_operator(t_token_list *start_token);
int					ft_cmdlen(t_token_list *begin_list, t_token_list *end_list);
int					ft_is_ionumber(const char *str);

int					ft_create_new_node(t_ast **ast,
										t_token_list *current_operator);

t_token				*ft_get_leaf_content(t_token_list *begin_cmd,
										const int size_tab);

int					ft_create_new_leaf(t_token_list *start_parsing,
										t_token_list *current_operator,
										t_ast **ast);

int					ft_to_ast(t_token_list *start_parsing,
								t_token_list *current_operator,
								t_ast **ast);

t_ast				*ft_get_ast(const char *cmd_user);
int					ft_is_valid_cmd(t_token_list *begin_list);

#endif
