# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#              #
#    Updated: 2019/06/14 19:03:44 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := RTv1
NPWD := $(CURDIR)/$(NAME)

CC := gcc -march=native -mtune=native -Ofast -flto -pipe
CC_DEBUG := gcc -march=native -mtune=native -g3 -D DEBUG -fsanitize=address
CFLAGS := -Wall -Wextra -Werror -Wunused -Wpedantic -Wno-type-limits
IFLAGS := -I $(CURDIR)/includes \
	-I $(CURDIR)/libft/includes \
	-I $(CURDIR)/libftsdl/includes \
	-I $(CURDIR)/libvectors/includes \
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
LIBVEC := $(CURDIR)/libvectors/libvectors.a
LIBFTSDL := $(CURDIR)/libftsdl/libftsdl.a
LIBPARSON := $(CURDIR)/libparson/libparson.a

LMAKE := make -C libft
LVMAKE := make -C libvectors
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
$(LIBVEC):
	@$(LVMAKE)
$(LIBFTSDL):
	@$(LSDLMAKE)
$(LIBPARSON):
	@$(LPARSONMAKE)

$(NAME): $(LIBFT) $(LIBVEC) $(LIBFTSDL) $(LIBPARSON) $(OBJ)
	@echo -n ' <q.p> | $(NPWD): '
	@$(CC) $(OBJ) $(LIBS) $(LIBFT) $(LIBVEC) $(LIBFTSDL) $(LIBPARSON) -o $(NAME)
	@echo "$(SUCCESS2)"

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
	@$(LMAKE) clean
	@$(LVMAKE) clean
	@$(LSDLMAKE) clean
	@$(LPARSONMAKE) clean

fclean: clean
	@$(DEL) $(NAME)
	@$(LMAKE) fclean
	@$(LVMAKE) fclean
	@$(LSDLMAKE) fclean
	@$(LPARSONMAKE) fclean
	@echo "$(INVERT)$(RED)deleted$(WHITE)$(INVERT): $(NPWD)$(WHITE)"

re: fclean all

norme:
	@echo "$(INVERT)$(RED) WARNING:$(WHITE)$(INVERT) for lib parson norme is not neccessary.$(WHITE)"
	@$(LMAKE) norme
	@$(LVMAKE) norme
	@$(LSDLMAKE) norme
	@echo "$(INVERT)norminette for $(GREEN)$(NAME)$(WHITE)$(INVERT):$(WHITE)"
	@norminette includes/
	@norminette $(SRCS)

.PHONY: re fclean clean all norme del pre debug debug_all
