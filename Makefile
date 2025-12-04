SRC := $(wildcard *.c)
OBJ := $(SRC:%.c=%.o)

CFLAGS := -std=c17

preep.exe: $(OBJ)
	@echo LD $@
	@clang $(CFLAGS) $(OBJ) -o $@

%.o: %.c
	@echo CC $@
	@clang $(CFLAGS) -c $< -o $@
