# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oishchen <oishchen@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 12:27:49 by oishchen          #+#    #+#              #
#    Updated: 2025/05/15 23:03:16 by oishchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDE = $(LIBNAME)/libft/includes/ \
		$(LIBNAME)/printf/includes/ \
		$(LIBNAME)/get_next_line/includes/
OWN_INCLUDE = include/

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g \
		$(addprefix -I, $(INCLUDE)) \
		-I$(OWN_INCLUDE)
RM = rm -rf

NAME = push_swap
CHECKER = checker

LIB_REPO_PASS = https://github.com/Zirael-leariZ/42_lib_mix
LIBNAME = mixlibft
LIBNAME_A = $(LIBNAME)/mixlibft.a
SRC_DIR = src
OBJ_DIR = obj

# Common source files (shared between both programs)
COMMON_FILES = check_input.c op1.c op2.c op_utils.c utils.c \
				find_median.c temp.c sort_utils.c back_sort_utils.c \
				op3.c is_sorted.c pivot_chunck_utils.c

# Program-specific source files
PUSH_SWAP_SRC = main.c
CHECKER_SRC = checker.c

# Object files
COMMON_OBJ = $(addprefix $(OBJ_DIR)/, $(COMMON_FILES:.c=.o))
PUSH_SWAP_OBJ = $(COMMON_OBJ) $(addprefix $(OBJ_DIR)/, $(PUSH_SWAP_SRC:.c=.o))
CHECKER_OBJ = $(COMMON_OBJ) $(addprefix $(OBJ_DIR)/, $(CHECKER_SRC:.c=.o))

all: $(NAME)

check: $(CHECKER)

$(NAME): $(PUSH_SWAP_OBJ) $(LIBNAME_A)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "BUILDING PUSH_SWAP"

$(CHECKER): $(CHECKER_OBJ) $(LIBNAME_A)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "BUILDING CHECKER"

$(LIBNAME):
	@if [ ! -d $(LIBNAME) ]; then \
		echo "CLONING LIBRARY_REPO"; \
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
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR) $(LIBNAME_A)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "BUILDING OBJ: $@"

clean:
	@make clean -C $(LIBNAME)
	@$(RM) $(OBJ_DIR)
	@echo "OBJECTS CLEANED"

fclean: clean
	@$(RM) $(NAME) $(CHECKER)
	@make fclean -C $(LIBNAME)
	@echo "FULL CLEAN COMPLETE"

re: fclean all

.PHONY: all clean fclean re check