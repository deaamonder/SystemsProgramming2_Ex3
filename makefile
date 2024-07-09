# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic

# Executables
EXEC = catan
TEST_EXEC = test

# Source files
SRCS = board.cpp card.cpp catan.cpp land.cpp player.cpp road.cpp settelment.cpp Demo.cpp test.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files
HEADERS = board.hpp card.hpp catan.hpp land.hpp player.hpp road.hpp settelment.hpp

# Default target
all: $(EXEC) $(TEST_EXEC)

# Link object files to create the executables
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(filter-out test.o, $^)

$(TEST_EXEC): $(filter-out Demo.o, $(OBJS)) test.o
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(EXEC) $(TEST_EXEC)

# Run the executable
run: $(EXEC)
	./$(EXEC)

# Run tests
run_test: $(TEST_EXEC)
	./$(TEST_EXEC)

.PHONY: all clean run run_test
