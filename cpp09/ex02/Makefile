CC = c++
FLAGS =  -Wall -Wextra -Werror
STD = 
NAME = PmergeMe

all: $(NAME)

$(NAME): *.cpp
	$(CC) $(FLAGS) $(STD) $^ -o $@

clean:
	rm -rf $(NAME)

re: clean all
