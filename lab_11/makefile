# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Targets
TARGET = matrix_app
OBJS = main.o Matrix.o

# Default rule
all: $(TARGET)

# Link objects into executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile .cpp to .o
main.o: main.cpp Matrix.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Matrix.o: Matrix.cpp Matrix.h
	$(CXX) $(CXXFLAGS) -c Matrix.cpp

# Clean build artifacts
clean:
	rm -f $(OBJS) $(TARGET)

# Rebuild from scratch
rebuild: clean all