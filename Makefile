# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 12:27:49 by oishchen          #+#    #+#              #
#    Updated: 2025/05/01 12:56:56 by oishchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE = $(LIBNAME)/libft/includes/ \
		$(LIBNAME)/printf/includes/
OWN_INCLUDE = include/

CC = cc
CFLAGS = -Wall -Wextra -Werror \
		$(addprefix -I, $(INCLUDE)) \
		-I$(OWN_INCLUDE)
RM = rm -rf

LIB_REPO_PASS = https://github.com/Zirael-leariZ/42_lib_mix
LIBNAME = mixlibft
LIBNAME_A = $(LIBNAME)/mixlibft.a
SRC_DIR = src
OBJ_DIR = obj
NAME = push_swap

C_FILES = check_input.c op1.c op2.c op_utils.c utils.c
SRC = $(addprefix $(SRC_DIR)/, $(C_FILES))
OBJ = $(addprefix $(OBJ_DIR)/, $(C_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ) $(LIBNAME_A)
	$(CC) $(CFLAGS) $(OBJ) $(LIBNAME_A) -o $@
	@echo "BULIDING PUSH_SWAP"

$(LIBNAME):
	@if [ ! -d $(LIBNAME) ]; then \
		echo "CLONNING LIBRARY_REPO"; \
		git clone $(LIB_REPO_PASS) $(LIBNAME); \
	else \
		echo "REPOSITORY EXISTS"; \
	fi

$(LIBNAME_A): | $(LIBNAME)
	@if [ ! -f $(LIBNAME_A) ]; then \
		echo "BUILDING LIBRARY"; \
		make -C $(LIBNAME); \
	else \
		echo "LIBRARY EXISTS"; \
	fi

$(OBJ_DIR):
	@if [ ! -d $(OBJ_DIR) ]; then \
		mkdir $(OBJ_DIR); \
	fi

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(LIBNAME_A)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "BULDING OBJ FROM SRC"

clean:
	@make clean -C $(LIBNAME)
	@$(RM) $(OBJ_DIR)
	@echo: "OBJ WERE CLEANED"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBNAME)
	@echo "EVERYTHING WAS CLEANED"