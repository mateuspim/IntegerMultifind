# Standard compiler, compilation flags, dependencies and object files.
CC = gcc
CFLAGS = -I.
DEPS = 
OBJ = p2.o

# DEPS macro declaration.
# First the compiler compiles the object files and then compiles the
# binaries, taking into account the dependencies.
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Compiles the IntegerMultifind executable.
# Compilation command: make
IntegerMultifind: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

# Cleans the directory (deleting the object files).
# Cleaning command: make clean
.PHONY: clean
clean:
	rm -rf *.o
