# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/25 11:27:37 by tmaluh            #+#    #+#              #
#    Updated: 2019/06/05 11:29:02 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftsdl.a
NPWD := $(CURDIR)/$(NAME)

ECHO := echo

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	ECHO += -e
	LC := gcc-ar
	PACKAGE_MANAGER := dnf
	INSTALLED_LIBS_LIST := $(shell $(PACKAGE_MANAGER) list)
endif
ifeq ($(UNAME_S),Darwin)
	LC := ar
	PACKAGE_MANAGER := brew
	INSTALLED_LIBS_LIST := $(shell $(PACKAGE_MANAGER) list)
endif

LC += rcs

SDL2_NECCESSARY_LIBS := sdl2 sdl2_image sdl2_ttf
SDL2_INSTALLED_LIBS := $(filter $(SDL2_NECCESSARY_LIBS), $(INSTALLED_LIBS_LIST))
SDL2_NOT_INSTALLED_LIBS := $(filter-out $(SDL2_INSTALLED_LIBS),$(SDL2_NECCESSARY_LIBS))

CC := gcc -march=native -mtune=native -Ofast -flto -pipe
CC_DEBUG := gcc -march=native -mtune=native -g3 -D DEBUG
CFLAGS := -Wall -Wextra -Werror -Wunused -Wno-type-limits
INC := -I ~/.brew/include -I $(CURDIR)/includes/ -I $(CURDIR)/../libft/includes

SRCS := $(abspath $(wildcard srcs/*.c srcs/*/*.c srcs/*/*/*.c srcs/*/*/*/*.c))
OBJS := $(SRCS:%.c=%.o)

DEL := rm -rf

WHITE := \033[0m
GREEN := \033[32m
RED := \033[31m
INVERT := \033[7m

SUCCESS = [$(GREEN)✓$(WHITE)]

all: $(SDL2_NOT_INSTALLED_LIBS) $(NAME)

$(SDL2_NOT_INSTALLED_LIBS):
ifneq ($(SDL2_NOT_INSTALLED_LIBS),)
	$(warning some SDL2 neccessary libs not founded, installing:)
	@$(PACKAGE_MANAGER) install $(SDL2_NOT_INSTALLED_LIBS)
endif

$(NAME): $(OBJS)
	@$(ECHO) "$(INVERT)"
	@$(ECHO) -n ' <=-=> | $(NPWD): '
	@$(LC) $(NAME) $(OBJS)
	@$(ECHO) "[$(GREEN)✓$(WHITE)$(INVERT)]$(WHITE)"
	@$(ECHO)

$(OBJS): %.o: %.c
	@$(ECHO) -n ' $@: '
	@$(CC) -c $(CFLAGS) $(INC) $< -o $@
	@$(ECHO) "$(SUCCESS)"

del:
	@$(DEL) $(OBJS)
	@$(DEL) $(NAME)
pre: del all
	@$(ECHO) "$(INVERT)$(GREEN)Successed re-build.$(WHITE)"
set_cc_debug:
	@$(eval CC=$(CC_DEBUG))
debug: set_cc_debug pre
	@$(ECHO) "$(INVERT)$(GREEN)Ready for debug.$(WHITE)"

clean:
	@$(DEL) $(OBJS)

fclean: clean
	@$(DEL) $(NAME)
	@$(ECHO) "$(INVERT)$(RED)deleted$(WHITE)$(INVERT): $(NPWD)$(WHITE)"

norme:
	@$(ECHO) "$(INVERT)norminette for $(GREEN)$(NAME)$(WHITE)$(INVERT):$(WHITE)"
	@norminette includes/
	@norminette $(SRCS)

re: fclean all

.PHONY: re fclean clean all
