CC = c++
FLAGS =  -Wall -Wextra 
STD = -std=c++98
NAME = scalar

all: $(NAME)

$(NAME): *.cpp
	$(CC) $(FLAGS) $(STD) $^ -o $@

clean:
	rm -rf $(NAME)

re: clean all
