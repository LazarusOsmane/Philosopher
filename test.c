/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christellenkouka <christellenkouka@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 09:33:55 by engooh            #+#    #+#             */
/*   Updated: 2022/05/14 12:24:29 by christellen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include "./share/libft/libft.h"

long int	timestamp(void)
{	
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	main(int ac, char **av)
{
	int			i;
	int			n = atoi(av[ac -1]);
	long int	tabs[n];
	long int	genese;

	printf("modulo %d\n", ((4 - 1) * 1));
	i = 0;
	genese = timestamp();
	while (++i <= n)
		tabs[i] = genese;
	printf("time ref  %ld\n", timestamp());
	i = 0;
	while (++i <= n)
		printf("time test %ld\n", genese);
	printf("time ref  %ld\n", timestamp());
	return (0);
}
