/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <engooh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 08:22:55 by engooh            #+#    #+#             */
/*   Updated: 2022/05/27 15:14:47 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

long int	timestamp(void)
{	
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ft_usleep(ssize_t time, t_philo *p)
{
	ssize_t		res;
	double		wt;

	wt = time / 10;
	res = timestamp() + time;
	while (timestamp() < res)
	{
		if (time > 1000)
			usleep(100);
		else
			usleep(wt);
		if (!check_death(p))
			break ;
	}
}

void	wait_philo(t_data *a, int i)
{
	while (++i < a->nbp_std)
		pthread_join(a->philo[i].thrid, NULL);
}

//take fork

void	tack_forck(t_philo *p)
{
	if (p->idx == p->data->nbp_std - 1)
	{
		pthread_mutex_lock(&p->data->philo[p->next].fork);
		status_fork(p);
		pthread_mutex_lock(&p->fork);
		status_fork(p);
		status_eat(p);
		pthread_mutex_unlock(&p->data->philo[p->next].fork);
		pthread_mutex_unlock(&p->fork);
	}
	else
	{
		pthread_mutex_lock(&p->fork);
		status_fork(p);
		pthread_mutex_lock(&p->data->philo[p->next].fork);
		status_fork(p);
		status_eat(p);
		pthread_mutex_unlock(&p->fork);
		pthread_mutex_unlock(&p->data->philo[p->next].fork);
	}
}

void	*routine(void *philo)
{
	t_philo	*p;

	p = philo;
	p->tte = timestamp();
	while (check_death(p))
	{
		tack_forck(p);
		status_sleep(p);
		status_think(p);
	}
	return (NULL);
}
