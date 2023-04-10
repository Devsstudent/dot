CFLAGS = -g -Wall -MMD -Wextra -Werror -std=c++98
CC = c++
OBJ = megaphone.o
NAME = megaphone
DD = megaphone.d

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf *.o
	rm -rf *.d

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all re fclean clean
-include $(DD)
