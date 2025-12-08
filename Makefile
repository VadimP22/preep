SRC := $(wildcard src/*.c)
OBJ := $(SRC:src/%.c=%.o)
OBJ_NO_MAIN := $(filter-out main.o, $(OBJ))

TEST_SRC := $(wildcard test/*.c)
TEST_EXE := $(TEST_SRC:%.c=%.exe)
TEST_RUN := $(TEST_EXE:test/%.exe=run_%.exe)

CFLAGS := -std=c17
CFLAGS += -g

all: preep.exe tests

preep.exe: $(OBJ)
	@echo LD $@
	@clang $(CFLAGS) $(OBJ) -o $@

tests: $(TEST_EXE)

test: tests $(TEST_RUN)

# Separate test and tests because Make removes tests executables after run

%.o: src/%.c
	@echo CC $@
	@clang $(CFLAGS) -c $< -o $@

test/%.exe: test/%.c $(OBJ_NO_MAIN)
	@echo CC (TEST) $@
	@clang -Isrc $(OBJ_NO_MAIN) $< -o $@ 


run_%.exe: test/%.exe
	@echo TEST $<
	@./$<