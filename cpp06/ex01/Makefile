CC = c++
FLAGS =  -Wall -Wextra 
STD = 
NAME = seri

all: $(NAME)

$(NAME): *.cpp
	$(CC) $(FLAGS) $(STD) $^ -o $@

clean:
	rm -rf $(NAME)

re: clean all
