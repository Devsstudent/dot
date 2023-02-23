CC = c++
CFLAGS = -std=c++98 -MMD -Werror -Wextra -Wall -g
OBJ = Harl.o main.o
DD = $(OBJ:.o=.d)
NAME = harl

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -I . $(OBJ) -o $(NAME)

%.o:%.cpp
	$(CC) $(CFLAGS) -I . -c $< -o $@

clean :
	rm -rf $(OBJ)
	rm -rf $(DD)

fclean : clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re fclean clean
-include $(DD)
