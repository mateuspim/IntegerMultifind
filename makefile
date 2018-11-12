# Standard compiler, compilation flags, dependencies and object files.
CC = gcc
CFLAGS = -lpthread
DEPS =
OBJ = main.o foo.o

# DEPS macro declaration.
# First the compiler compiles the object files and then compiles the
# binaries, taking into account the dependencies.
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Compiles the "multifind" executable.
# Compilation command: make
multifind: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

# Cleans the directory (deleting the object files).
# Cleaning command: make clean
.PHONY: clean
clean:
	rm -rf *.o
