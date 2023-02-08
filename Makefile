NAME = containers

CC = clang++

FLAGS = --std=c++98 -Wall -Wextra -Werror

SRCS = ./vector/tests/vector.cpp ./stack/tests/stack.cpp ./map/tests/map.cpp ./utils/tests/utils.cpp main.cpp 

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

utils:
	@make && ./containers utils && make fclean

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re map vector stack utils
