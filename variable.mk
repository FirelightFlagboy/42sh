# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    variable.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/28 09:18:27 by fbenneto          #+#    #+#              #
#    Updated: 2018/05/11 09:58:14 by fbenneto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########
# Name #
########

NAME 		= 42sh

###############
# compilateur #
###############

CC 		= clang
CFLAGS	= -Wall -Werror -Wextra
LCFLAGS = -ltermcap

#######
# Lib #
#######

#############
# FT_PRINTF #
#############

FT_PRINTF_DIR		=\
	ft_printf/

FT_PRINTF_NAME		=\
	libftprintf.a

FT_PRINTF_INC_DIR	=\
	$(FT_PRINTF_DIR)includes/

FT_PRINTF_INC_NAME	=\
	ft_printf.h\

FT_PRINTF_INC		= $(addprefix $(FT_PRINTF_INC_DIR), $(FT_PRINTF_INC_NAME))
FT_PRINTF			= $(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_NAME))
LCFLAGS				+= $(FT_PRINTF)

#########
# LIBFT #
#########
LIBFT_DIR			=\
	libft/

LIBFT_NAME			=\
	libft.a

LIBFT_INC_DIR		=\
	$(LIBFT_DIR)includes\

LIBFT_INC_NAME		=\
	get_next_line.h\
	libft.h\

LIBFT_INC			= $(addprefix $(LIBFT_INC_DIR), $(LIBFT_INC_NAME))
LIBFT				= $(addprefix $(LIBFT_DIR), $(LIBFT_NAME))
LCFLAGS				+= $(LIBFT)
###########
# include #
###########

INC_DIR 	= includes/
INC_NAME	=\
	debug.h\
	argv.h\
	builtin.h\
	cleaning.h\
	completion.h\
	core.h\
	edition.h\
	env.h\
	evalcmd.h\
	hash.h\
	history.h\
	lexer_parser.h\
	my_errno.h\
	other.h\
	quotes.h\
	reading.h\
	sh.h\
	sh_define.h\
	sh_inc.h\
	sh_struct.h\
	sig.h\
	terminall.h\

INC_ALL		= $(addprefix $(INC_DIR), $(INC_NAME))
INC_DIR_ALL	=\
	$(INC_DIR)\
	$(LIBFT_INC_DIR)\
	$(FT_PRINTF_INC_DIR)\

ICFLAGS 	= $(addprefix -I, $(INC_DIR_ALL))

#######
# Src #
#######

SRC_DIR 	= ./srcs/

SRC_ARGV_DIR=\
	argv/

SRC_ARGV_NAME=\
	ft_fill_arg.c\
	ft_get_arg.c\
	ft_get_argv.c\
	ft_len_arg.c\

SRC_ARGV = $(addprefix $(SRC_ARGV_DIR), $(SRC_ARGV_NAME))

SRC_EVALCMD_DIR=\
	evalcmd/

SRC_EVALCMD_NAME=\
	evalcmd.c\
	ft_eval_ast.c\
	ft_eval_built.c\
	ft_eval_cmd_no_fork.c\
	ft_eval_direct_cmd.c\
	ft_eval_hash.c\
	ft_eval_pipe.c\
	ft_eval_pipe2.c\

SRC_EVALCMD = $(addprefix $(SRC_EVALCMD_DIR), $(SRC_EVALCMD_NAME))

SRC_REDIR_DIR=\
	redir/

SRC_REDIR_NAME=\
	redir.c\
	redir_agre.c\
	redir_heredoc.c\
	redir_heredoc_2.c\
	redir_input.c\
	redir_output.c\

SRC_REDIR = $(addprefix $(SRC_REDIR_DIR), $(SRC_REDIR_NAME))

SRC_MAIN_DIR=\
	main/

SRC_MAIN_NAME=\
	main.c\
	start.c\

SRC_MAIN = $(addprefix $(SRC_MAIN_DIR), $(SRC_MAIN_NAME))

SRC_QUOTES_DIR=\
	quotes/

SRC_QUOTES_NAME=\
	ft_isescapechar.c\
	ft_splittreat.c\
	quotes_env.c\
	quotes.c\
	quotes_utils.c\
	splitquote_str2.c\
	treatquotes.c\

SRC_QUOTES = $(addprefix $(SRC_QUOTES_DIR), $(SRC_QUOTES_NAME))

SRC_READING_DIR=\
	reading/

SRC_READING_NAME=\
	mange_buffer.c\
	prompt_utils.c\
	prompt.c\
	reader.c\
	validating.c\

SRC_READING = $(addprefix $(SRC_READING_DIR), $(SRC_READING_NAME))

SRC_ERRNO_DIR=\
	errno/

SRC_ERRNO_NAME=\
	my_errno_arg.c\
	my_errno_atoi.c\
	my_errno_error.c\
	my_errno_ft_strerror.c\
	my_errno_str.c\
	my_errno_warnx.c\
	my_errno.c\

SRC_ERRNO = $(addprefix $(SRC_ERRNO_DIR), $(SRC_ERRNO_NAME))

SRC_OTHER_DIR=\
	other/

SRC_OTHER_NAME=\
	ft_access.c\

SRC_OTHER = $(addprefix $(SRC_OTHER_DIR), $(SRC_OTHER_NAME))

SRC_SIG_DIR=\
	sig/

SRC_SIG_NAME=\
	sig.c\
	interceptsig.c\
	resig.c\

SRC_SIG = $(addprefix $(SRC_SIG_DIR), $(SRC_SIG_NAME))

SRC_HASH_DIR=\
	hash/

SRC_HASH_NAME=\
	ft_hash.c\
	ft_refresh_hash.c\
	get_hash.c\

SRC_HASH = $(addprefix $(SRC_HASH_DIR), $(SRC_HASH_NAME))

SRC_TERMINAL_DIR=\
	terminal/

SRC_TERMINAL_NAME=\
	move_page.c\
	cursor_left_right.c\
	cut_copy_line.c\
	edition_cursor_right.c\
	edition_utils.c\
	edition.c\
	initialize_util.c\
	initialize.c\
	modify_buffer.c\
	setterm.c\
	sh.c\
	shell_env.c\

SRC_TERMINAL = $(addprefix $(SRC_TERMINAL_DIR), $(SRC_TERMINAL_NAME))

SRC_BUILTINS_DIR=\
	builtins/

SRC_BUILTINS_NAME =\
	builtin_history.c\
	built_history_utils.c\
	built_history_utils2.c\
	builtin_echo.c\
	builtin_env.c\
	builtin_env_exe.c\
	builtin_env_prints.c\
	builtin_env_prints2.c\
	builtin_env_utilities.c\
	builtin_env_utilities2.c\
	builtin_exit.c\
	builtin_getenv.c\
	builtin_setenv.c\
	builtin_unsetenv.c\
	cd2.c\
	cd3.c\
	cd4.c\
	cd5.c\
	cd6.c\
	cd_main.c\
	setenv_funcs.c\
	change_env_export.c\
	export_guillemets.c\
	ft_export.c\
	ft_set.c\
	ft_unset.c\
	new_locvar.c\
	set_guillemets.c\
	get_strn_pos.c\
	malloc_error.c\
	read_main.c\
	read_getopt.c\
	read_workopt.c\
	read_work.c\
	read_end.c\
	read_end_assign.c\

SRC_BUILTINS = $(addprefix $(SRC_BUILTINS_DIR), $(SRC_BUILTINS_NAME))

SRC_CLEANUP_DIR=\
	cleanup/

SRC_CLEANUP_NAME= cleaning.c\

SRC_CLEANUP = $(addprefix $(SRC_CLEANUP_DIR), $(SRC_CLEANUP_NAME))

SRC_COMPLETION_DIR=\
	completion/

SRC_COMPLETION_NAME=\
	c_utils.c\
	c_utils2.c\
	c_utils3.c\
	c_utils4.c\
	clean_list.c\
	define_pading.c\
	ft_print.c\
	get_dir.c\
	get_info.c\
	get_list.c\
	name_completion.c\
	name_utils.c\
	padding_utils.c\
	put_options.c\
	tab_arrows.c\
	tab_completion.c\
	tab_lst_sort.c\
	tab_name.c\
	try_up.c\

SRC_COMPLETION = $(addprefix $(SRC_COMPLETION_DIR), $(SRC_COMPLETION_NAME))

SRC_ENV_LIST_DIR=\
	env_list/

SRC_ENV_LIST_NAME=\
	ft_getenv.c\
	utils.c\
	utils2.c\

SRC_ENV_LIST = $(addprefix $(SRC_ENV_LIST_DIR), $(SRC_ENV_LIST_NAME))

SRC_ERR_DIR=\
	err/

SRC_ERR_NAME=\
	main_err.c\

SRC_ERR = $(addprefix $(SRC_ERR_DIR), $(SRC_ERR_NAME))

SRC_HISTORY_DIR=\
	history/

SRC_HISTORY_NAME=\
	history_search.c\
	exclamation.c\
	history.c\
	single_exclamation.c\
	single_exclamation_utils.c\
	utils.c\

SRC_HISTORY = $(addprefix $(SRC_HISTORY_DIR), $(SRC_HISTORY_NAME))

SRC_DEBUG_DIR=\
	debug/

SRC_DEBUG_NAME=\
	debug_ast.c\
	debug_hash.c\
	debug_argv.c\
	debug_ast_box.c\

SRC_DEBUG = $(addprefix $(SRC_DEBUG_DIR), $(SRC_DEBUG_NAME))

SRC_LEXER_PARSER_DIR=\
	lexer_parser/

SRC_LEXER_PARSER_NAME=\
	ast.c\
	ast_create_leafs_and_nodes.c\
	cmd_user_to_ast.c\
	control_operators.c\
	frees.c\
	ft_get_leaf_content.c\
	ft_get_lex_word_function.c\
	ft_is_valid_cmd.c\
	ft_strchr_index.c\
	lex_quotes.c\
	lexer.c\
	redirections_operators.c\
	tests_functions.c\
	tokens.c

SRC_LEXER_PARSER = $(addprefix $(SRC_LEXER_PARSER_DIR), $(SRC_LEXER_PARSER_NAME))

SRC_DIR_ALL =\
	$(SRC_MAIN_DIR)\
	$(SRC_QUOTES_DIR)\
	$(SRC_READING_DIR)\
	$(SRC_SIG_DIR)\
	$(SRC_TERMINAL_DIR)\
	$(SRC_BUILTINS_DIR)\
	$(SRC_CLEANUP_DIR)\
	$(SRC_COMPLETION_DIR)\
	$(SRC_ENV_LIST_DIR)\
	$(SRC_ERR_DIR)\
	$(SRC_HISTORY_DIR)\
	$(SRC_ERRNO_DIR)\
	$(SRC_HASH_DIR)\
	$(SRC_LEXER_PARSER_DIR)\
	$(SRC_EVALCMD_DIR)\
	$(SRC_REDIR_DIR)\
	$(SRC_ARGV_DIR)\
	$(SRC_OTHER_DIR)\
	$(SRC_DEBUG_DIR)\

SRC_NAME =\
	$(SRC_DEBUG)\
	$(SRC_OTHER)\
	$(SRC_ARGV)\
	$(SRC_EVALCMD)\
	$(SRC_REDIR)\
	$(SRC_ERRNO)\
	$(SRC_HASH)\
	$(SRC_MAIN)\
	$(SRC_QUOTES)\
	$(SRC_READING)\
	$(SRC_SIG)\
	$(SRC_TERMINAL)\
	$(SRC_BUILTINS)\
	$(SRC_CLEANUP)\
	$(SRC_COMPLETION)\
	$(SRC_ENV_LIST)\
	$(SRC_ERR)\
	$(SRC_HISTORY)\
	$(SRC_LEXER_PARSER)

SRC_ALL		= $(addprefix $(SRC_DIR), $(SRC_NAME))

#######
# Obj #
#######

OBJ_DIR		= ./obj/
OBJ_NAME	= $(SRC_NAME:.c=.o)
OBJ_DIR_ALL = $(addprefix $(OBJ_DIR), $(SRC_DIR_ALL))
OBJ_ALL		= $(addprefix $(OBJ_DIR), $(OBJ_NAME))
