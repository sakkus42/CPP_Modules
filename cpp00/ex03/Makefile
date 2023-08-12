CC = c++
FLAGS = -Wall -Wextra -Werror -g
STD = -std=c++98
NAME = tests

all: $(NAME)

$(NAME): *.cpp
	$(CC) $(FLAGS) $(STD) $^ -o $@

clean:
	rm -rf $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all
