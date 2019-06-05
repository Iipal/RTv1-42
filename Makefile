# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#              #
#    Updated: 2019/06/05 18:24:45 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := RTv1
NPWD := $(CURDIR)/$(NAME)

ECHO := echo

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	ECHO += -e

	PACKAGE_MANAGER := sudo dnf
	INSTALLED_LIBS_LIST := $(shell rpm -qa)
	SDL2_NECCESSARY_LIBS := SDL2-devel-2.0.9-3.fc30.x86_64 \
							SDL2_ttf-devel-2.0.15-2.fc30.x86_64 \
							SDL2_image-devel-2.0.4-2.fc30.x86_64
endif
ifeq ($(UNAME_S),Darwin)
	LIBSINC := -I ~/.brew/include
	LIBS := -L ~/.brew/lib -rpath ~/.brew/lib

	PACKAGE_MANAGER := brew
	INSTALLED_LIBS_LIST := $(shell $(PACKAGE_MANAGER) list)
	SDL2_NECCESSARY_LIBS := sdl2 sdl2_image sdl2_ttf
endif

LIBS += -lSDL2 -lSDL2_ttf -lSDL2_image -lm

SDL2_INSTALLED_LIBS := $(filter $(SDL2_NECCESSARY_LIBS), $(INSTALLED_LIBS_LIST))
SDL2_NOT_INSTALLED_LIBS := $(filter-out $(SDL2_INSTALLED_LIBS),$(SDL2_NECCESSARY_LIBS))

CC := gcc -march=native -mtune=native -Ofast -flto -pipe
CC_DEBUG := gcc -march=native -mtune=native -g3 -D DEBUG
CFLAGS := -Wall -Wextra -Werror -Wunused
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

all: $(SDL2_NOT_INSTALLED_LIBS) $(NAME)

$(SDL2_NOT_INSTALLED_LIBS):
ifneq ($(SDL2_NOT_INSTALLED_LIBS),)
	$(warning some SDL2 neccessary libs not founded, installing:)
	$(PACKAGE_MANAGER) install $(SDL2_NOT_INSTALLED_LIBS)
endif

$(OBJ): %.o: %.c
	@$(ECHO) -n ' $@: '
	@$(CC) -c $(CFLAGS) $(LIBSINC) $(IFLAGS) $< -o $@
	@$(ECHO) "$(SUCCESS)"

$(LIBFT):
	@$(LMAKE)

$(LIBFTSDL):
	@$(LSDLMAKE)

$(NAME): $(LIBFT) $(LIBFTSDL) $(OBJ)
	@$(ECHO) -n ' <q.p> | $(NPWD): '
	@$(CC) $(OBJ) $(LIBS) $(LIBFT) $(LIBFTSDL) -o $(NAME)
	@$(ECHO) "[$(INVERT)$(GREEN)✓$(WHITE)]"

del:
	@$(DEL) $(OBJ)
	@$(DEL) $(NAME)

pre: del all
	@$(ECHO) "$(INVERT)$(GREEN)Successed re-build.$(WHITE)"

set_cc_debug:
	@$(eval CC=$(CC_DEBUG))

debug: set_cc_debug pre
	@$(ECHO) "$(INVERT)$(GREEN)Ready for debug.$(WHITE)"
clean:
	@$(DEL) $(OBJ)
	@$(LSDLMAKE) clean
	@$(LMAKE) clean

fclean: clean
	@$(LSDLMAKE) fclean
	@$(LMAKE) fclean
	@$(DEL) $(NAME)
	@$(ECHO) "$(INVERT)$(RED)deleted$(WHITE)$(INVERT): $(NPWD)$(WHITE)"

norme:
	@$(LMAKE) norme
	@$(LSDLMAKE) norme
	@$(ECHO) "$(INVERT)norminette for $(GREEN)$(NAME)$(WHITE)$(INVERT):$(WHITE)"
	@norminette includes/
	@norminette $(SRCS)

re: fclean all

.PHONY: all fclean clean re
