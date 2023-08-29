CC = c++
FLAGS =  -Wall -Werror -Wextra
STD = -std=c++98
NAME = brain

all: $(NAME)

$(NAME): *.cpp
	$(CC) $(FLAGS) $(STD) $^ -o $@

clean:
	rm -rf $(NAME)

re: clean all
