SRC = src/main.c src/creat_philo.c src/routine_philo.c src/destroy_philo.c src/status_philo.c
OBJ = ${SRC:%.c=%.o}
CFLAG = -g3 -pthread -Wall -Wextra -Werror

all: philo

philo: $(OBJ)
	gcc $(CFLAG) $(OBJ) -o $@  share/libft/libft.a

%.o: %.c
	cd share/libft/ && make && cd ../../
	#cd share/Printf/ && make && cd ../../
	gcc $(CFLAG) -c $^ -o $@ 

clean: 
	rm src/*.o

fclean: clean 
	rm philo

re: fclean all

.PHONY: all fclean clean re bonus
