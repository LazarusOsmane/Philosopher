SRC = src/main.c src/routine.c src/init.c src/destroy.c src/join.c src/status.c
OBJ = ${SRC:%.c=%.o}
CFLAG = -g3 -pthread -Wall -Wextra -Werror

all: philo

philo: $(OBJ)
	gcc $(CFLAG) $(OBJ) -o $@  share/libft/libft.a

%.o: %.c
	cd share/libft/ && make && cd ../../
	#cd share/Printf/ && make && cd ../../
	gcc $(CFLAG) -c $^ -o $@ 

ff: $(OBJ)
	gcc -fsanitize=thread $(CFLAG) $(OBJ) -o philo  share/libft/libft.a

dd: $(OBJ)
	gcc -fsanitize=address $(CFLAG) $(OBJ) -o philo  share/libft/libft.a

clean: 
	rm src/*.o

fclean: clean 
	rm philo

re: fclean all

.PHONY: all fclean clean re bonus
