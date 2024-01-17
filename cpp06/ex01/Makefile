CC = c++
FLAGS =  -Wall -Wextra 
STD = -std=c++98
NAME = seri

all: $(NAME)

$(NAME): *.cpp
	$(CC) $(FLAGS) $(STD) $^ -o $@

clean:
	rm -rf $(NAME)

re: clean all
