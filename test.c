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


int main(void)
{
	int	tabs[7] = {1, 2, 3, 4, 5, 6, 7};

	printf("nbr %d\n", tabs[((1 - 1) + 7) % 7]);
	return (0);
}
