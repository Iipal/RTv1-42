# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#              #
#    Updated: 2019/06/12 21:15:19 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := RTv1
NPWD := $(CURDIR)/$(NAME)

CC := gcc -march=native -mtune=native -Ofast -flto -pipe
CC_DEBUG := gcc -march=native -mtune=native -g3 -D DEBUG -fsanitize=address
CFLAGS := -Wall -Wextra -Werror -Wunused -Wpedantic
IFLAGS := -I $(CURDIR)/includes \
	-I $(CURDIR)/libft/includes \
	-I $(CURDIR)/libftsdl/includes \
	-I $(CURDIR)/libvectors/includes
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
LMAKE := make -C libft
LIBFTSDL := $(CURDIR)/libftsdl/libftsdl.a
LSDLMAKE := make -C libftsdl
LIBVEC := $(CURDIR)/libvectors/libvectors.a
LVMAKE := make -C libvectors

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
$(LIBFTSDL):
	@$(LSDLMAKE)
$(LIBVEC):
	@$(LVMAKE)

$(NAME): $(LIBFT) $(LIBVEC) $(LIBFTSDL) $(OBJ)
	@echo -n ' <q.p> | $(NPWD): '
	@$(CC) $(OBJ) $(LIBS) $(LIBFT) $(LIBVEC) $(LIBFTSDL) -o $(NAME)
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
	@$(LVMAKE) clean
	@$(LSDLMAKE) clean
	@$(LMAKE) clean

fclean: clean
	@$(LVMAKE) fclean
	@$(LSDLMAKE) fclean
	@$(LMAKE) fclean
	@$(DEL) $(NAME)
	@echo "$(INVERT)$(RED)deleted$(WHITE)$(INVERT): $(NPWD)$(WHITE)"

re: fclean all

norme:
	@$(LMAKE) norme
	@$(LSDLMAKE) norme
	@$(LVMAKE) norme
	@echo "$(INVERT)norminette for $(GREEN)$(NAME)$(WHITE)$(INVERT):$(WHITE)"
	@norminette includes/
	@norminette $(SRCS)

.PHONY: re fclean clean all norme del pre debug debug_all
