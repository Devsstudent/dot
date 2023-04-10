CC = c++
CFLAGS = -MMD -Wall -Werror -Wextra -std=c++98
OBJ = Animal.o main.o Cat.o Dog.o Brain.o
DD = $(OBJ:.o=.d)
NAME = Animal

all: $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o *.d

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY:all re clean fclean

-include $(DD)
