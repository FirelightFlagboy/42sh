# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/10 16:31:48 by anonymous          #+#    #+#              #
#    Updated: 2018/05/09 11:29:48 by fbenneto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

########
# Name #
########

NAME = libft.a
MKNAME = libft

############
# COMPILER #
############

CC = gcc
CC =clang
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	CFLAGS += -O3
endif
ifeq ($(UNAME_S), Darwin)
	CFLAGS += -Wall -Werror -Wextra
endif

###########
# Include #
###########

ICFLAGS = -I./includes

INC_DIR =\
	includes/

INC_NAME =\
	libft.h\
	get_next_line.h\

INC = $(addprefix $(INC_DIR), $(INC_NAME))

#######
# Src #
#######

SRC_DIR = srcs/

SRC_NAME =\
ft_itoa_cte.c ft_charput.c ft_pow.c\
ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c\
ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_memmove.c ft_memset.c\
ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_lstdelone.c ft_lstiter.c\
ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c\
ft_memcpy.c ft_memdel.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c\
ft_putstr_fd.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c\
ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strlcpy.c\
ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strnstr.c\
ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strncat.c ft_strncmp.c\
ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strtrim.c ft_tolower.c ft_toupper.c\
ft_lstrev.c ft_lstsort.c ft_lstsize.c ft_lstforeach.c ft_lstmerge.c ft_lstrmif.c\
ft_ptrequ.c ft_get_path.c ft_lst_create_elem.c ft_lst_removenode.c ft_basename.c\
ft_lst_remove_if.c ft_count_umax_digits.c ft_itoa_ularge.c\
ft_put_justified_str.c ft_put_justified_nbr.c ft_putchar_if.c ft_lst_in_list.c\
ft_lstadd_back.c ft_lst_clear.c ft_char_arr_len.c ft_strisblank.c ft_str2del.c\
ft_str2len.c ft_strndelat.c ft_str2new.c ft_str2dup.c get_next_line.c\
ft_str3join.c ft_strlen_until.c ft_str2join.c ft_strtrim_char.c ft_strndup.c\
ft_word_count.c ft_lst_new_add_back.c ft_str_replace.c ft_arr_push.c\
ft_arr_del_at.c ft_arr_includes.c ft_arr_inner_join.c ft_splitquotes.c\
ft_isspace.c ft_isquotes.c ft_put2str.c ft_strsplitin.c ft_arr_to_str.c\
ft_isinquotes.c ft_isescaped.c ft_strnreplace.c ft_strlower.c ft_free_tchar.c\

SRC = $(addprefix $(SRC_DIR), $(SRC_NAME))

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_NAME))

#############
# ECHO RULE #
#############

ifneq ($(words $(MAKECMDGOALS)),1)
.DEFAULT_GOAL = all
%:
		@$(MAKE) $@ --no-print-directory -rRf $(firstword $(MAKEFILE_LIST))
else
ifndef ECHO
T := $(shell $(MAKE) $(MAKECMDGOALS) --no-print-directory \
		-nrRf $(firstword $(MAKEFILE_LIST)) \
		ECHO="COUNTTHIS" | grep -c "COUNTTHIS")

N := x
C = $(words $N)$(eval N := x $N)
ECHO = printf "\r\e[K[%-10s:%10s%%]" "$(MKNAME)" "`expr "\`expr $C '*' 100 / $T\`"`"
endif

#########
# MACRO #
#########

NC		= "\\033[0m"
RED		= "\\033[31m"
GREEN	= "\\033[32m"
YELLOW	= "\\033[33m"
BLUE	= "\\033[34m"
MAJENTA	= "\\033[35m"
CYAN	= "\\033[36m"
BOLD	= "\\033[1m"
CHEK	= "✓"
OK		= "$(GREEN)$(CHEK)$(NC)"

########
# Rule #
########

.NOTPARALLEL :

$(SRC) : $(INC)

all : $(NAME)

$(NAME) : $(OBJ_DIR) $(OBJ)
	@$(ECHO)
	@printf " doing ar rc $(BOLD)$(CYAN)$@$(NC)"
	@ar rc $@ $(OBJ)
	@printf ' '$(OK)
	@$(ECHO)
	@printf " doing ranlib $(BOLD)$(CYAN)$@$(NC)"
	@ranlib $@
	@printf ' '$(OK)'\n'

$(OBJ_DIR) :
	@$(ECHO)
	@printf " creating folder $(MAJENTA)$(BOLD)$@$(NC)"
	@mkdir -p $@
	@printf ' '$(OK)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c ./Makefile
	@$(ECHO)
	@printf " compile $(BOLD)$(YELLOW)$@$(NC) "
	@$(CC) $(FLAGS) $(ICFLAGS) -c -o $@ $<
	@printf $(OK)

clean :
	@$(ECHO)
	@printf " rm all $(BOLD)$(RED)obj file$(NC)"
	@rm -rf $(OBJ_DIR)
	@printf ' '$(OK)

fclean : clean
	@$(ECHO)
	@printf " rm $(BOLD)$(CYAN)$(NAME)$(NC)"
	@rm -f $(NAME)
	@printf ' '$(OK)'\n'

re : fclean all

print-% :
	@echo $($*)

.PHONY : all clean fclean re
endif
