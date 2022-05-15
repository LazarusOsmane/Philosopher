/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christellenkouka <christellenkouka@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 14:16:35 by christellen       #+#    #+#             */
/*   Updated: 2022/05/15 00: by christellen      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"

void    status_eat(t_all *all, t_philosopher *philo)
{
	int		N;

	if (!philo->nbp)
		N = all->nbp - 1;
	else 
		N = philo->nbp - 1;
	pthread_mutex_lock(&all->philo[N].eat);
    pthread_mutex_lock(&philo->eat);
    printf("[%ld] [%d] has taken a fork\n", timestamp() - all->genese, philo->nbp );
	printf("[%ld] [%d] has taken a fork\n", timestamp() - all->genese, philo->nbp);
	printf("[%ld] [%d] is eating\n", timestamp() - all->genese, philo->nbp);
	philo->tte = timestamp();
    usleep(all->tte * 1000);
	pthread_mutex_unlock(&philo->eat);
	pthread_mutex_unlock(&all->philo[N].eat);
}

void    status_sleep(t_all *all, t_philosopher *philo)
{
    pthread_mutex_lock(&all->sleep);
    printf("[%ld] [%d] is sleeping\n", timestamp() - all->genese, philo->nbp);
    usleep(all->tts * 1000);
    printf("[%ld] [%d] is thinking\n", timestamp() - all->genese, philo->nbp);
    pthread_mutex_unlock(&all->sleep);
}

void    *status_dead(void *argc)
{
    t_all   *all;
    int     i;
    int     n;

    all = argc; 
    pthread_mutex_lock(&all->if_dead);
    n = all->nbp;
    while (n)
    {
        i = -1;
        while (++i < all->nbp)
        {
            if (((timestamp() - all->genese) - all->philo[i].tte >= all->ttd))
            {
                printf("[%ld] [%d] died\n", timestamp() - all->genese, i);
                all->philo[i].is_dead = 0;
                n--;
            }
        }
    } 
    pthread_mutex_unlock(&all->if_dead);
    return (NULL);
}