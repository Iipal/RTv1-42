# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 14:43:13 by tmaluh            #+#    #+#              #
#    Updated: 2019/05/20 10:50:47 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := RTv1
NPWD := $(CURDIR)/$(NAME)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	ECHO := echo -e
	LIBS := -lSDL2 -lSDL2_ttf -lm
endif
ifeq ($(UNAME_S),Darwin)
	ECHO := echo
	LIBSINC := -F $(CURDIR)/libftsdl/frameworks \
		-I $(CURDIR)/libftsdl/frameworks/SDL2.framework/Headers \
		-I $(CURDIR)/libftsdl/frameworks/SDL2_ttf.framework/Headers
	LIBS := -F $(CURDIR)/libftsdl/frameworks -rpath \
		$(CURDIR)/libftsdl/frameworks -framework SDL2 -framework SDL2_ttf
endif

CC := gcc -march=native -mtune=native -Ofast -flto -pipe
CC_DEBUG := gcc -march=native -mtune=native -g3 -D DEBUG
CFLAGS := -Wall -Wextra -Werror -Wunused
IFLAGS := -I $(CURDIR)/includes/ \
	-I $(CURDIR)/libft/includes/ -I $(CURDIR)/libftsdl/includes/ \

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

norme:
	@norminette includes/
	@norminette $(SRC)
	@norminette libft/includes/
	@norminette libft/srcs/*/*.c
	@norminette libftsdl/includes/
	@norminette libftsdl/srcs/*.c \
		libftsdl/srcs/colors_math/clr/*.c \
		libftsdl/srcs/colors_math/clr/*/*.c \
		libftsdl/srcs/colors_math/clrs/*.c \
		libftsdl/srcs/colors_math/clrs/*/*.c

re: fclean all

.PHONY: all fclean clean re
