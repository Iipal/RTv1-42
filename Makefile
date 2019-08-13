# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#              #
#    Updated: 2019/08/13 09:34:01 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := RTv1
NPWD := $(CURDIR)/$(NAME)

CC_BASE := gcc -march=native -mtune=native

CC := $(CC_BASE) -Ofast -pipe -flto
CC_DEBUG := $(CC_BASE) -g3 -D DEBUG
CC_PROFILE := $(CC_BASE) -no-pie -pg -O0

CFLAGS := -Wall -Wextra -Werror -Wunused -Wno-type-limits
IFLAGS := -I $(CURDIR)/includes \
	-I $(CURDIR)/libft/includes \
	-I $(CURDIR)/libwu/includes \
	-I $(CURDIR)/libftsdl/includes \
	-I $(CURDIR)/libvectors \
	-I $(CURDIR)/libparson

LIBSINC :=
LIBS :=

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	LIBSINC += -I ~/.brew/include
	LIBS += -L ~/.brew/lib -rpath ~/.brew/lib
endif
LIBS += -lSDL2 -lSDL2_ttf -lSDL2_image -lm

SRCS := $(abspath $(wildcard srcs/*.c srcs/*/*.c srcs/*/*/*.c))
OBJ := $(SRCS:.c=.o)

LIBFT := $(CURDIR)/libft/libft.a
LIBWU := $(CURDIR)/libwu/libwu.a
LIBFTSDL := $(CURDIR)/libftsdl/libftsdl.a
LIBPARSON := $(CURDIR)/libparson/libparson.a

LMAKE := make -C libft
LWUMAKE := make -C libwu
LSDLMAKE := make -C libftsdl
LPARSONMAKE := make -C libparson

DEL := rm -rf

WHITE := \033[0m
BGREEN := \033[42m
GREEN := \033[32m
RED := \033[31m
INVERT := \033[7m

SUCCESS := [$(GREEN)✓$(WHITE)]
SUCCESS2 := [$(INVERT)$(GREEN)✓$(WHITE)]

all: $(NAME)

$(OBJ): %.o: %.c
	@echo -n ' $@: '
	@$(CC) -c $(CFLAGS) $(LIBSINC) $(IFLAGS) $< -o $@
	@echo "$(SUCCESS)"

$(LIBFT):
	@$(LMAKE)
$(LIBWU):
	@$(LWUMAKE)
$(LIBFTSDL):
	@$(LSDLMAKE)
$(LIBPARSON):
	@$(LPARSONMAKE)

$(NAME): $(LIBFT) $(LIBWU) $(LIBFTSDL) $(LIBPARSON) $(OBJ)
	@echo -n ' <q.p> | $(NPWD): '
	@$(CC) $(OBJ) $(LIBS) $(LIBFT) $(LIBWU) $(LIBFTSDL) $(LIBPARSON) -o $(NAME)
	@echo "$(SUCCESS2)"

del:
	@$(DEL) $(OBJ)
	@$(DEL) $(NAME)

pre: del all
	@echo "$(INVERT)$(GREEN)Successed re-build.$(WHITE)"

.PHONY: clear_pre
clear_pre:
	pre

set_cc_debug:
	@$(eval CC=$(CC_DEBUG))
debug_all: set_cc_debug pre
	@echo "$(INVERT)$(NAME) $(GREEN)ready for debug.$(WHITE)"
debug: set_cc_debug all
	@echo "$(INVERT)$(NAME) $(GREEN)ready for debug.$(WHITE)"

set_cc_profle:
	@$(eval CC=$(CC_PROFILE))
profile_all: set_cc_profle pre
	@echo "$(INVERT)$(NAME) $(GREEN)ready for profile.$(WHITE)"
profile: set_cc_profle all
	@echo "$(INVERT)$(NAME) $(GREEN)ready for profile.$(WHITE)"

profile_allr: set_cc_profle
	@$(LMAKE) profile_all
	@$(LVECMAKE) profile_all
	@$(LSDLMAKE) profile_all
	@$(LPARSONMAKE) profile_all
	@make profile_all

clean:
	@$(DEL) $(OBJ)
	@$(LMAKE) clean
	@$(LSDLMAKE) clean
	@$(LPARSONMAKE) clean

fclean: clean
	@$(DEL) $(NAME)
	@$(LMAKE) fclean
	@$(LSDLMAKE) fclean
	@$(LPARSONMAKE) fclean
	@echo "$(INVERT)$(RED)deleted$(WHITE)$(INVERT): $(NPWD)$(WHITE)"

re: fclean all

norme_all:
	@echo "$(INVERT)$(RED) WARNING:$(WHITE)$(INVERT) for lib parson norme is not neccessary.$(WHITE)"
	@$(LMAKE) norme
	@$(LSDLMAKE) norme
	@echo "$(INVERT)norminette for $(GREEN)$(NAME)$(WHITE)$(INVERT):$(WHITE)"
	@norminette includes/
	@norminette $(SRCS)

norme:
	@echo "$(INVERT)norminette for $(GREEN)$(NAME)$(WHITE)$(INVERT):$(WHITE)"
	@norminette includes/
	@norminette $(SRCS)

.PHONY: re fclean clean all norme_all norme del pre debug debug_all
