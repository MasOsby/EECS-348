# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Target program
TARGET = prog

# Object files
OBJS = main.o isEven.o isOdd.o

all: $(TARGET)

# Default build rule
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile main.o
main.o: main.c isEven.h isOdd.h
	$(CC) $(CFLAGS) -c main.c

# Compile isEven.o
isEven.o: isEven.c isEven.h
	$(CC) $(CFLAGS) -c isEven.c

# Compile isOdd.o
isOdd.o: isOdd.c isOdd.h
	$(CC) $(CFLAGS) -c isOdd.c

# Clean rule to remove binaries and object files
clean:
	rm -f $(TARGET) $(OBJS)