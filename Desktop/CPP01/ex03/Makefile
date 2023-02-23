CC = c++
CFLAGS = -std=c++98 -Werror -Wextra -Wall -MMD -g
OBJ= $(addprefix obj/, HumanA.o HumanB.o Weapon.o main.o)
DD = $(OBJ:.o=.d)
NAME = weapon

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

obj/%.o:src/%.cpp | object
	$(CC) $(CFLAGS) -I ./ -c $< -o $@

object :
	mkdir -p obj

clean:
	rm -rf obj/

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean re fclean all
-include $(DD)
