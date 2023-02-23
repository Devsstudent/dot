CC = c++
CFLAGS = -Wall -Werror -Wextra -MMD -g -std=c++98
NAME = HI_THIS_IS_BRAIN

all: $(NAME)

$(NAME) : main.o
	$(CC) $(CFLAGS) main.o -o $(NAME)

%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf main.o main.d

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean all re fclean
-include main.d
