CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

TARGET = lab13
SRC = main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)