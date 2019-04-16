# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#              #
#    Updated: 2019/04/16 17:45:58 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := RTv1
NPWD := $(CURDIR)/$(NAME)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	ECHO := echo -e
	LIBS := -lSDL2 -lm
endif
ifeq ($(UNAME_S),Darwin)
	ECHO := echo
	LIBSINC := -F $(CURDIR)/frameworks
	LIBS := -F $(CURDIR)/frameworks -rpath $(CURDIR)/frameworks -framework SDL2
endif

#   -march=native       - Setups compiler to use all available CPU instructions for
#                           optimizing compiling time
#   -mtune=native       - Setups compiler to compiling all correctly for
#                           current system architecture on which project compiling
#   -flto               - Enable Link Time Optimization
#   -Ofast              - MAXIMUM OPTIMIZATION
CC_DEBUG := gcc -march=native -g3 -D DEBUG
CC := gcc -march=native -mtune=native -flto -Ofast
CFLAGS := -Wall -Wextra -Werror -Wunused
IFLAGS := -I $(CURDIR)/includes/ -I $(CURDIR)/libft/includes/ -I $(CURDIR)/libftsdl/includes/

SRC := $(abspath $(wildcard srcs/*.c))
SRC += $(abspath $(wildcard srcs/*/*.c))
OBJ := $(SRC:.c=.o)

LIBFT := $(CURDIR)/libft/libft.a
LMAKE := make -C libft
LIBFTSDL := $(CURDIR)/libftsdl/libftsdl.a
LSDLMAKE := make -C libftsdl

WHITE := \033[0m
BGREEN := \033[42m
GREEN := \033[32m
RED := \033[31m
INVERT := \033[7m

SUCCESS = [$(GREEN)✓$(WHITE)]

DEL := rm -rf

all: $(NAME)

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

pre: del $(NAME)
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

re: fclean all

.PHONY: all fclean clean re
