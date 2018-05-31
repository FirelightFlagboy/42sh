/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:31:29 by fbenneto          #+#    #+#             */
/*   Updated: 2018/05/05 14:48:56 by fbenneto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_STRUCT_H
# define SH_STRUCT_H

# include <term.h>
# include "libft.h"

typedef enum		e_token_family
{
	WORD,
	OP_CTRL,
	OP_REDIR
}					t_token_family;

typedef	enum		e_token_name
{
	NEWLINE_OP,
	NORMAL_WORD,
	IO_NUMBER,
	LESS,
	DLESS,
	LESS_AND,
	GREAT,
	DGREAT,
	GREAT_AND,
	PIPE_OP,
	OR_OP,
	AND_OP,
	BACKGROUND_OP,
	SEMI_COLON_OP
}					t_token_name;

typedef struct		s_token
{
	t_token_family	family;
	t_token_name	name;
	char			*value;
}					t_token;

typedef struct		s_token_list
{
	t_token				token;
	struct s_token_list	*next;
}					t_token_list;

typedef struct		s_ast
{
	t_token			*node_tokens;
	int				size_tab;
	struct s_ast	*left_son;
	struct s_ast	*right_son;
}					t_ast;

typedef struct		s_hash
{
	char			*key;
	char			*path;
	struct s_hash	*next;
}					t_hash;

typedef struct		s_heredoc
{
	int				type;
	char			*txt;
}					t_heredoc;

/*
** list of environment variables
*/

typedef struct		s_envl
{
	struct s_envl	*next;
	char			*name;
	char			*value;
}					t_envl;

typedef struct		s_quotes
{
	t_bool			was_quoted;
	t_bool			dquote;
	t_bool			squote;
	t_bool			bquote;
	t_bool			escape;
	t_bool			parenthesis;
	t_bool			curly_bracket;
	t_bool			oneline;
}					t_quotes;

typedef struct		s_h_lst
{
	char			*cmd;
	int				index;
	struct s_h_lst	*next;
	struct s_h_lst	*prev;
}					t_h_lst;

/*
** list of history command
** size: nb of command in history
*/

typedef struct		s_hist
{
	int				size;
	int				at_index;
	struct s_h_lst	*list;
}					t_hist;

/*
** terminal
*/

typedef struct		s_term
{
	struct termios	term;
	int				tc_ok;
	int				tc_in;
	int				tc_len;
	int				prompt_len;
	int				prompt_line;
	int				winsize_x;
	int				ws_col;
	int				ws_row;
	size_t			max_len;
}					t_term;

/*
** shell
** env varibles in env_list
*/

typedef struct		s_env_s
{
	int				set;
	int				unset;
	int				ignore;
	int				cmd;
	int				null;
}					t_env_s;

typedef struct		s_tab
{
	char			*content;
	char			*name;
	char			*perm;
	size_t			cursor;
	size_t			place;
	size_t			col;
	size_t			page;
	struct s_tab	*next;
	struct s_tab	*prev;
}					t_c_tab;

struct				s_put
{
	int				c_line;
	size_t			c_col;
	size_t			len;
	size_t			m_len;
	int				max_len;
}					;

struct				s_pad
{
	size_t			line_s;
	size_t			col_s;
	size_t			page_s;
	size_t			cols;
	size_t			pages;
	size_t			largest;
	size_t			len_x;
	size_t			len_y;
	size_t			max_x;
	size_t			max_y;
}					t_pad;

typedef struct		s_locvar
{
	char			*var;
	char			*val;
	int				isexport;
	int				isguillemet;
	struct s_locvar	*next;
	struct s_locvar	*prev;
}					t_locvar;

typedef struct		s_sh
{
	struct s_locvar	*locvar;
	char			**env;
	char			**cmd;
	char			*buff;
	t_hash			**hash;
	char			*hash_pwd;
	t_ast			*ast;
	t_envl			*env_list;
	t_hist			*history;
	t_term			*term;
	t_quotes		*q;
	pid_t			child;
	struct termios	official;
	int				heredoc_fd;
	int				basic_fd[4];
	int				ttfd;
	char			*clipboard;
	char			*tmp_buff;
	int				exit;
	int				ret;
	int				inhere;
	char			*hist_dir;
	void			(*sig)(int);
	int				debug;
	char			prompt[64];
}					t_sh;

typedef struct stat		t_stat;
typedef struct dirent	t_dirent;

#endif
