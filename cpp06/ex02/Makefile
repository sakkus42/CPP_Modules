CC = c++
FLAGS =  -Wall -Wextra 
STD = -std=c++98
NAME = dynamic

all: $(NAME)

$(NAME): *.cpp
	$(CC) $(FLAGS) $(STD) $^ -o $@

clean:
	rm -rf $(NAME)

re: clean all
