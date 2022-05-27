#include <time.h>
#include <stdio.h>
#include <wait.h>
# include <pthread.h>
#include <sys/time.h>

long int	timestamp(void)
{	
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}



int	check_death(int mut)
{
	pthread_mutex_t	death;

	if (pthread_mutex_init(&death, NULL))
		return (0);
	pthread_mutex_lock(&death);
	if (42 == mut)
	{
		printf("ko\n");
		pthread_mutex_unlock(&death);
		return (0);
	}
	printf("ok\n");
	pthread_mutex_unlock(&death);
	return (1);
}

void	ft_usleep(ssize_t time)
{
	ssize_t		res;
	ssize_t		ras;

	res = timestamp();
	ras = res + 10;
	res += time;
	while (timestamp() < res)
	{
		if (timestamp() >= ras && check_death(45))
		{
			ras += 10;
		}
	}
}

int main(void)
{
	long int start = timestamp();

	printf("%ld\n", timestamp() - start);
	ft_usleep(500);
	printf("%ld\n", timestamp() - start);
	return (0);
}
