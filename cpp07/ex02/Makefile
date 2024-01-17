CC = c++
FLAGS =  -Wall -Wextra -Werror
STD = -std=c++98
NAME = template

all: $(NAME)

$(NAME): *.cpp
	$(CC) $(FLAGS) $(STD) $^ -o $@

clean:
	rm -rf $(NAME)

re: clean all
