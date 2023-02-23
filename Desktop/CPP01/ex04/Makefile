CC = c++
CFLAGS = -MMD -Werror -Wextra -std=c++98 -Wall
OBJ = main.o 
NAME = sed
DD = main.d

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

main.o : main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o main.o

clean :
	rm -rf main.o main.d

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re fclean clean

-include $(DD)
