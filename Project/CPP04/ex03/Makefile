CC = c++
CFLAGS = -g -MMD -std=c++98 -Wall -Werror -Wextra
OBJ = Cure.o Ice.o AMateria.o Character.o main.o MateriaSource.o
NAME = ex03
DD = $(OBJ:.o=.d)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o *.d

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: all re fclean clean

-include $(DD)
