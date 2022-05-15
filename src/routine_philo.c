/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christellenkouka <christellenkouka@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:19:24 by christellen       #+#    #+#             */
/*   Updated: 2022/05/14 20:13:45christellen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long int	timestamp(void)
{	
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int		wait_philo(t_all *all, int i)
{
	i = -1;
	pthread_detach(all->philo[all->nbp].thrid);
	while (++i < all->nbp)
		pthread_join(all->philo[i].thrid, NULL);
	return (0);
}

void	*routine(void *argc)
{
	t_all			*all;
	t_philosopher	*philo;

	philo = argc;
	all = philo->ptr_all;
	pthread_mutex_lock(&all->main);
	while (1)
	{
		if (philo->is_dead)
		{
			status_eat(all, philo);
			status_sleep(all, philo);
		}
		else
			return (NULL);
	}
	pthread_mutex_unlock(&all->main);
	return (NULL);
}

