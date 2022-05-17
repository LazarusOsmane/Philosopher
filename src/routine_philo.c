/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 08:22:55 by engooh            #+#    #+#             */
/*   Updated: 2022/05/17 18:03:19 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long int	timestamp(void)
{	
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(ssize_t time)
{
	ssize_t		t;

	t = timestamp();
	while (timestamp() - t < time)
	{
	}
}

void	wait_philo(t_data *a, int i)
{
	while (++i < a->nbp_std)
		pthread_join(a->philo[i].thrid, NULL);
}

void	status_philo(t_philo *p, char *str, int status)
{
	if (status == 1)
	{
		pthread_mutex_lock(&p->data->lock);
		p->ect++;
		p->tte = timestamp();
		printf("[%ld] [%d] %s", timestamp() - p->data->genese, p->idx, str);
		ft_usleep(p->data->tte_std);
		pthread_mutex_unlock(&p->data->lock);
	}
	if (status == 2)
	{
		pthread_mutex_lock(&p->data->lock);
		printf("[%ld] [%d] %s", timestamp() - p->data->genese, p->idx, str);
		ft_usleep(p->data->tts_std);
		pthread_mutex_unlock(&p->data->lock);
	}
	if (status == 3)
	{
		pthread_mutex_lock(&p->data->lock);
		printf("[%ld] [%d] %s", timestamp() - p->data->genese, p->idx, str);
		pthread_mutex_unlock(&p->data->lock);
	}
}

void	*routine(void *philo)
{
	t_philo	*p;

	p = philo;
	pthread_mutex_lock(&p->fork);
	if (!pthread_mutex_lock(&p->data->philo[p->next].fork))
	{
		pthread_mutex_lock(&p->data->eat);
		status_philo(p, "is eating\n", 1);
		pthread_mutex_unlock(&p->data->eat);
	}
	else
	{
		status_philo(p, "is sleeping\n", 2);
		status_philo(p, "is thinking\n", 3);
	}
	pthread_mutex_unlock(&p->data->philo[p->next].fork);
	pthread_mutex_unlock(&p->fork);
	return (NULL);
}
