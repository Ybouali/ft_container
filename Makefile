COMPILER = clang++

FLAGS = --std=c++98 -Wall -Wextra -Werror



all:
	@$(COMPILER) $(FLAGS) ./map/tests/map.cpp -o map.out
	@$(COMPILER) $(FLAGS) ./stack/tests/stack.cpp -o stack.out
	@$(COMPILER) $(FLAGS) ./vector/tests/vector.cpp -o vector.out

clean:
	@rm -f vector.out map.out stack.out