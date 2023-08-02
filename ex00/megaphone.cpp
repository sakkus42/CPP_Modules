#include <iostream>

int	message(std::string message, int exit_flag){
	std::cout << message << std::endl;
	if (exit_flag)
		exit(1);
	return (0);
}

void	to_upper_string(std::string *str){
	for (size_t i = 0; i < str->length(); i++)
	{
		if (isupper(str[0][i]))
			continue;
		str[0][i] = toupper(str[0][i]);
	}
}

int	main(int ac, char *arv[]){
	ac == 1 ? message("Missing Argument", 1) : 0;
	std::string *res = new std::string[ac];
	int	y = 0;
	for (int i = 1; i < ac; i++)
	{
		res[y] = arv[i];
		to_upper_string(&res[y]);
		std::cout << res[y];
		if (i + 1 != ac)
			std::cout << " ";
		y++;
	}
	return (0);
}