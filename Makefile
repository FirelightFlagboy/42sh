# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbenneto <fbenneto@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/08 10:46:43 by anonymous          #+#    #+#              #
#    Updated: 2018/05/04 13:59:54 by fbenneto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./variable.mk

MKNAME = 42sh

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

#########
# Rules #
#########

.NOTPARALLEL :

all: $(NAME)

# $(SRC_ALL) : $(INC_ALL)

$(NAME): $(FT_PRINTF) $(LIBFT) $(OBJ_DIR) $(OBJ_DIR_ALL) $(OBJ_ALL)
	@$(ECHO)
	@printf " compile binary $(BOLD)$(CYAN)$@$(NC)"
	@$(CC) $(CFLAGS) $(LCFLAGS) -o $@ $(OBJ_ALL)
	@printf ' '$(OK)'\n'

$(OBJ_DIR):
	@$(ECHO)
	@printf " creating folder $(MAJENTA)$(BOLD)$@ dir$(NC)"
	@mkdir -p $@
	@printf ' '$(OK)

$(OBJ_DIR_ALL) :
	@$(ECHO)
	@printf " creating folder $(MAJENTA)$(BOLD)$@$(NC)"
	@mkdir -p $@
	@printf ' '$(OK)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(FT_PRINTF):
	@make -C $(FT_PRINTF_DIR)

$(SRC_ALL) : $(INC_ALL)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c ./Makefile ./variable.mk $(INC_ALL)
	@$(ECHO)
	@printf " compile $(YELLOW)$(BOLD)$<$(NC)"
	@$(CC) $(CFLAGS) $(ICFLAGS) -o $@ -c $<
	@printf ' '$(OK)

clean:
	@rm -rf $(OBJ_DIR)
	@$(ECHO)
	@printf " rm all $(BOLD)$(RED)obj file"
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(FT_PRINTF_DIR)
	@printf ' '$(NC)$(OK)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make naelc -C $(FT_PRINTF_DIR)
	@$(ECHO)
	@printf " rm $(BOLD)$(CYAN)$(NAME)"
	@rm -f $(NAME)
	@printf ' '$(NC)$(OK)'\n'

re:
	@make -C ./ fclean
	@make -C ./ all

print-% :
	@echo $($*)

.PHONY : re fclean clean all
endif
