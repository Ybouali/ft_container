NAME = containers

CC = clang++

FLAGS = --std=c++98 -Wall -Wextra -Werror -fsanitize=address -g3

SRCS = ./vector/tests/vector.cpp ./stack/tests/stack.cpp ./map/tests/map.cpp main.cpp 

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)

.cpp.o: ${SRCS}
	@$(CC) $(FLAGS) -c $< -o $@


map:
	@make && ./containers map && make fclean

vector:
	@make && ./containers vector && make fclean

stack:
	@make && ./containers stack && make fclean

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re map vector stack
