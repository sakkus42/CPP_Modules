CC = c++
FLAGS = -Wall -Wextra -Werror -g

NAME = PhoneBook

all: $(NAME)

$(NAME): *.cpp
	$(CC) $(FLAGS) $(STD) $^ -o $@

clean:
	rm -rf $(NAME)

fclean:
	rm -rf $(NAME)

re: fclean all
