# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/25 11:27:37 by tmaluh            #+#    #+#              #
#    Updated: 2019/05/19 11:36:22 by tmaluh           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftsdl.a
NPWD := $(CURDIR)/$(NAME)

ECHO := echo

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	ECHO += -e
	LC := gcc-ar
endif
ifeq ($(UNAME_S),Darwin)
	LC := ar
endif

LC += rcs

CC := gcc -march=native -mtune=native -Ofast -flto -pipe
CFLAGS := -Wall -Wextra -Werror -Wunused -Wno-type-limits
INC := -F $(CURDIR)/frameworks -I $(CURDIR)/includes/

SRC_D := srcs/
SRCS := $(abspath $(wildcard $(SRC_D)/*.c))
SRCS += $(abspath $(wildcard $(SRC_D)/*/*.c))
SRCS += $(abspath $(wildcard $(SRC_D)/*/*/*.c))
SRCS += $(abspath $(wildcard $(SRC_D)/*/*/*/*.c))
OBJS := $(SRCS:%.c=%.o)

DEL := rm -rf

WHITE := \033[0m
GREEN := \033[32m
RED := \033[31m
INVERT := \033[7m

SUCCESS = [$(GREEN)✓$(WHITE)]

all: $(NAME)

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

clean:
	@$(DEL) $(OBJS)

fclean: clean
	@$(DEL) $(NAME)
	@$(ECHO) "$(INVERT)$(RED)deleted$(WHITE)$(INVERT): $(NPWD)$(WHITE)"

re: fclean all

.PHONY: re fclean clean all
