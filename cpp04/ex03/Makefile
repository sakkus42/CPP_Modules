CC = c++
FLAGS =  -g
STD = -std=c++98
NAME = interface

all: $(NAME)

$(NAME): *.cpp *.hpp
	$(CC) $(FLAGS) $(STD) $^ -o $@

clean:
	rm -rf $(NAME)

re: clean all
