CC = c++
FLAGS =  -Wall -Wextra 
STD = 
NAME = ScalarConverter

all: $(NAME)

$(NAME): *.cpp
	$(CC) $(FLAGS) $(STD) $^ -o $@

clean:
	rm -rf $(NAME)

re: clean all
