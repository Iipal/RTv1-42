# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#              #
#    Updated: 2019/06/11 09:08:14 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := RTv1
NPWD := $(CURDIR)/$(NAME)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LIBSINC :=
	LIBS :=
endif
ifeq ($(UNAME_S),Darwin)
	LIBSINC := -I ~/.brew/include
	LIBS := -L ~/.brew/lib -rpath ~/.brew/lib
endif

LIBS += -lSDL2 -lSDL2_ttf -lSDL2_image -lm

CC := gcc -march=native -mtune=native -Ofast -flto -pipe
CC_DEBUG := gcc -march=native -mtune=native -g3 -D DEBUG
CFLAGS := -Wall -Wextra -Werror -Wunused -Wpedantic
IFLAGS := -I $(CURDIR)/includes/ \
	-I $(CURDIR)/libft/includes/ -I $(CURDIR)/libftsdl/includes/ \

SRCS := $(abspath $(wildcard srcs/*.c srcs/*/*.c srcs/*/*/*.c))
OBJ := $(SRCS:.c=.o)

LIBFT := $(CURDIR)/libft/libft.a
LMAKE := make -C libft
LIBFTSDL := $(CURDIR)/libftsdl/libftsdl.a
LSDLMAKE := make -C libftsdl

DEL := rm -rf

WHITE := \033[0m
BGREEN := \033[42m
GREEN := \033[32m
RED := \033[31m
INVERT := \033[7m

SUCCESS = [$(GREEN)✓$(WHITE)]

all: $(NAME)

$(OBJ): %.o: %.c
	@echo -n ' $@: '
	@$(CC) -c $(CFLAGS) $(LIBSINC) $(IFLAGS) $< -o $@
	@echo "$(SUCCESS)"

$(LIBFT):
	@$(LMAKE)

$(LIBFTSDL):
	@$(LSDLMAKE)

$(NAME): $(LIBFT) $(LIBFTSDL) $(OBJ)
	@echo -n ' <q.p> | $(NPWD): '
	@$(CC) $(OBJ) $(LIBS) $(LIBFT) $(LIBFTSDL) -o $(NAME)
	@echo "[$(INVERT)$(GREEN)✓$(WHITE)]"

del:
	@$(DEL) $(OBJ)
	@$(DEL) $(NAME)

pre: del all
	@echo "$(INVERT)$(GREEN)Successed re-build.$(WHITE)"

set_cc_debug:
	@$(eval CC=$(CC_DEBUG))
debug_all: set_cc_debug pre
	@echo "$(INVERT)$(NAME) $(GREEN)ready for debug.$(WHITE)"
debug: set_cc_debug all
	@echo "$(INVERT)$(NAME) $(GREEN)ready for debug.$(WHITE)"

clean:
	@$(DEL) $(OBJ)
	@$(LSDLMAKE) clean
	@$(LMAKE) clean

fclean: clean
	@$(LSDLMAKE) fclean
	@$(LMAKE) fclean
	@$(DEL) $(NAME)
	@echo "$(INVERT)$(RED)deleted$(WHITE)$(INVERT): $(NPWD)$(WHITE)"

re: fclean all

norme:
	@$(LMAKE) norme
	@$(LSDLMAKE) norme
	@echo "$(INVERT)norminette for $(GREEN)$(NAME)$(WHITE)$(INVERT):$(WHITE)"
	@norminette includes/
	@norminette $(SRCS)

.PHONY: re fclean clean all norme del pre debug debug_all
