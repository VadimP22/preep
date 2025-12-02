SRC := $(wildcard *.c)
OBJ := $(SRC:%.c=%.o)

preep.exe: $(OBJ)
	@echo LD $@
	@clang $(OBJ) -o $@

%.o: %.c
	@echo CC $@
	@clang -c $< -o $@
