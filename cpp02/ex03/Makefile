CC = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror -g 

NAME = Fixed

all: $(NAME)

$(NAME): *.cpp
	$(CC) $(FLAGS) $(STD) $^ -o $@

clean:
	rm -rf $(NAME)

re: clean all