#include <time.h>
#include <stdio.h>
#include <wait.h>
#include <unistd.h>
#include <sys/time.h>

long int	timestamp(void)
{	
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(ssize_t time)
{
	ssize_t		res;
	ssize_t		ras;

	res = timestamp() + time;
	while (timestamp() < res)
	{
		if ()
	}
}

int main(void)
{
	long int start = timestamp();

	printf("%ld\n", timestamp() - start);
	ft_usleep(1000);
	printf("%ld\n", timestamp() - start);
	return (0);
}
