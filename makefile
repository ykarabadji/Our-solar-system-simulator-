# Makefile for Solar System Simulator

# Compiler
CXX = g++

# Compiler flags
# CXXFLAGS = -Wall -std=c++17

# SFML libraries
LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Source files
SRC = system.cpp

# Output executable
TARGET = system

# Default target
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LIBS)

# Clean build files
clean:
	rm -f $(TARGET)
