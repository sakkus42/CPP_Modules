CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror
STD = -std=c++98
NAME = Fixed

all: $(NAME)

$(NAME): *.cpp
	$(CC) $(FLAGS) $(STD) $^ -o $@

clean:
	rm -rf $(NAME)

re: clean all