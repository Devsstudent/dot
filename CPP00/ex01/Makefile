CFLAGS = -g -Wall -MMD -Wextra -Werror -std=c++98
CC = c++
OBJ = main.o PhoneBook.o
NAME = annuaire
DD = $(OBJ:.o=.d)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CGLAGS) $(OBJ) -I ./ -o $(NAME)

%.o:%.cpp
	$(CC) $(CFLAGS) -I ./ -c $< -o $@

clean :
	rm -rf *.o
	rm -rf *.d

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all re fclean clean
-include $(DD)
