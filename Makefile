CXX = clang++
CXX_FLAGS = -std=c++20 -g -fstandalone-debug -Iincludes -Wall -Wextra -Werror -fsanitize=address,null -fno-omit-frame-pointer -O0 -gdwarf-4

exec: bin/exec
tests: bin/tests
bin/exec: ./src/driver.cc ./src/board.cc ./src/ship.cc ./includes/board.hpp ./includes/gameplay.hpp ./includes/node.hpp ./includes/ship.hpp 
	$(CXX) $(CXX_FLAGS) ./src/driver.cc ./src/ship.cc ./src/board.cc ./src/gameplay.cc -o $@

bin/tests: ./tests/tests.cc ./src/board.cc ./src/ship.cc ./includes/node.hpp ./includes/gameplay.hpp  ./includes/ship.hpp ./includes/board.hpp
	$(CXX) $(CXX_FLAGS) ./tests/tests.cc ./src/board.cc ./src/ship.cc ./src/gameplay.cc -o $@
.DEFAULT_GOAL := exec

.PHONY: exec tests clean

clean:
	rm -rf bin/*