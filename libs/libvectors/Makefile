UNAME_S := $(shell uname -s)
AR :=
ifeq ($(UNAME_S),Linux)
	AR := llvm-ar
endif
ifeq ($(UNAME_S),Darwin)
	AR := llvm-ar
endif
AR_FLAGS := -rcs

all:
	@$(shell echo "void foo_dummy_blyad(void){return;}" > a.c)
	@$(shell clang -c a.c -o a.o -flto -Ofast -fpic)
	@$(AR) $(AR_FLAGS) libvectors.a a.o

debug_all: fclean multi
debug: multi

sanitize_all: fclean multi
sanitize: multi

del:
del_libs:

pre:
re:

clean:
fclean:
norme:
	@norminette includes/

.PHONY: re fclean clean norme del pre sanitize sanitize_all debug debug_all
