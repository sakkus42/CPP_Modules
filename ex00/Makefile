CC = c++
FLAGS = -Wall -Wextra -Werror
STD = -std=c++98
NAME = megaphone

all: $(NAME)

$(NAME): megaphone.cpp
	$(CC) $(FLAGS) $(STD) $^ -o $@

clean:
	rm -rf $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all
