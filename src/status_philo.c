/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:37:29 by engooh            #+#    #+#             */
/*   Updated: 2022/05/26 14:22:00 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

int	status_death(t_data *a, int i)
{
	while (++i < a->nbp_std)
	{
		pthread_mutex_lock(&a->lock);
		if ((((timestamp() - a->philo[i].tte) >= a->ttd_std)
					|| a->philo[i].ect == a->ect_std))
		{
			pthread_mutex_lock(&a->death);
			a->dead = 0;
			pthread_mutex_unlock(&a->death);
			printf("[%ld] [%d] has died\n", timestamp() - a->philo[i].tte,
				a->philo[i].idx);
			pthread_mutex_unlock(&a->lock);
			return (0);
		}
		pthread_mutex_unlock(&a->lock);
	}
	return (1);
}

void	status_eat(t_philo *p)
{
	if (!check_death(p))
		return ;
	pthread_mutex_lock(&p->data->lock);
	p->ect++;
	p->tte = timestamp();
	printf("[%ld] [%d] is eating\n", p->tte - p->data->genese, p->idx);
	pthread_mutex_unlock(&p->data->lock);
	ft_usleep(p->s_tte, p);
}

void	status_sleep(t_philo *p)
{
	if (!check_death(p))
		return ;
	pthread_mutex_lock(&p->data->lock);
	printf("[%ld] [%d] is sleeping\n", timestamp() - p->data->genese,
		p->idx);
	pthread_mutex_unlock(&p->data->lock);
	ft_usleep(p->s_tts, p);
}

void	status_think(t_philo *p)
{
	if (!check_death(p))
		return ;
	pthread_mutex_lock(&p->data->lock);
	printf("[%ld] [%d] is thinking\n", timestamp() - p->data->genese,
		p->idx);
	pthread_mutex_unlock(&p->data->lock);
}

void	status_fork(t_philo *p)
{
	if (!check_death(p))
		return ;
	pthread_mutex_lock(&p->data->lock);
	printf("[%ld] [%d] has taken a fork\n", timestamp() - p->data->genese,
		p->idx);
	pthread_mutex_unlock(&p->data->lock);
}
