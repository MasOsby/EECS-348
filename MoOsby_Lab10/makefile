# Simple Makefile for Basic Calculator
CXX = g++
CXXFLAGS = -std=c++17 -Wall

TARGET = calculator
SRC = calc.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)