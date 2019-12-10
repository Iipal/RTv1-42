NAME := $(notdir $(CURDIR)).a
NPWD := $(CURDIR)/$(NAME)

CC := clang

CFLAGS_WARN := -Wall -Wextra -Werror -Wunused

CFLAGS_DEBUG := -glldb
CFLAGS_SANITIZE := $(CFLAGS_DEBUG) -fsanitize=address
CFLAGS_OPTIMIZE := -march=native -mtune=native -Ofast -pipe -flto -fpic

CFLAGS := $(CFLAGS_OPTIMIZE)

ifneq (,$(wildcard ./includes))
IFLAGS := $(addprefix -I,$(shell find ./includes -type d))
endif
ifneq (,$(wildcard ../libvectors/includes)) # libvectors dependency
IFLAGS += $(addprefix -I,$(shell find ../libvectors/includes -type d))
endif

ifneq (,$(wildcard ./srcs))
SRCS := $(shell find srcs -name "*.c")
OBJS := $(SRCS:.c=.o)
endif

ECHO := echo
MAKE := make
DEL := rm -rf

NPROCS := 1

ARFLAGS = -Trcs

UNAME_S := $(shell uname -s)
# Linux Specifications:
ifeq ($(UNAME_S),Linux)
# Only for Red-Hat systems where -e param isn't enabled by default in echo built-in command.
# Remove this line if you have enabled -e option in echo command.
ECHO += -e

NPROCS := $(shell grep -c ^processor /proc/cpuinfo)
MAKE_PARALLEL_FLAGS := -j $(NPROCS) -l $(NPROCS) -Otarget
AR := llvm-ar
endif

# MacOS Specifications:
ifeq ($(UNAME_S),Darwin)
# Only for MacOS where brew install path on home directory
#  or user don't have enought permissions to install latest version of GNUMake on system globally.
# Remove this line if in your MacOS system already installed GNUMake 4.0.0 or later.
 ifneq ($(wildcard ~/.brew/bin/gmake),)
	MAKE := ~/.brew/bin/gmake
	NPROCS := $(shell sysctl -n hw.ncpu)
	MAKE_PARALLEL_FLAGS := -j $(NPROCS) -l $(NPROCS) -Otarget
 endif

AR := ar
endif

MAKE += --no-print-directory

CLR_INVERT := \033[7m
CLR_UNDERLINE := \033[4m

CLR_GREEN := \033[32m
CLR_WHITE := \033[0m
CLR_BLUE := \033[34m

MSG_SUCCESS := [$(CLR_GREEN)✓$(CLR_WHITE)]
MSG_BSUCCESS := [$(CLR_BLUE)✓$(CLR_WHITE)]
MSG_SUCCESS_NO_CLR := [✓]
